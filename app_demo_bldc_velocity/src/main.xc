/* INCLUDE BOARD SUPPORT FILES FROM module_board-support */
#include <CORE_C22-rev-a.inc>
#include <IFM_DC100-rev-b.inc>

/**
 * @file test_velocity-ctrl.xc
 * @brief Test illustrates usage of profile velocity control
 * @author Synapticon GmbH (www.synapticon.com)
 */

#include <print.h>
#include <hall_server.h>
#include <qei_server.h>
#include <pwm_service_inv.h>
#include <commutation_server.h>
#include <refclk.h>
#include <velocity_ctrl_client.h>
#include <velocity_ctrl_server.h>
#include <xscope_wrapper.h>
#include <profile.h>
#include <drive_modes.h>
#include <statemachine.h>
#include <profile_control.h>
#include <qei_client.h>
#include <internal_config.h>
//Configure your motor parameters in config/bldc_motor_config.h
#include <bldc_motor_config.h>

#define ENABLE_XSCOPE

on stdcore[IFM_TILE]: clock clk_adc = XS1_CLKBLK_1;
on stdcore[IFM_TILE]: clock clk_pwm = XS1_CLKBLK_REF;

void xscope_initialise_1()
{
    xscope_register(2,
            XSCOPE_CONTINUOUS, "0 actual_velocity", XSCOPE_INT,	"n",
            XSCOPE_CONTINUOUS, "1 target_velocity", XSCOPE_INT, "n");
}

/* Test Profile Velocity function */
void profile_velocity_test(chanend c_velocity_ctrl)
{
	int target_velocity = 1000;	 		// rpm
	int acceleration 	= 100;			// rpm/s
	int deceleration 	= 100;			// rpm/s

#ifdef ENABLE_XSCOPE
	xscope_initialise_1();
#endif


	while(1){

	    target_velocity = 1000;
	    set_profile_velocity( target_velocity, acceleration, deceleration, MAX_PROFILE_VELOCITY, c_velocity_ctrl);

	    target_velocity = 0;				// rpm
	    set_profile_velocity( target_velocity, acceleration, deceleration, MAX_PROFILE_VELOCITY, c_velocity_ctrl);

        target_velocity = -1000;
        set_profile_velocity( target_velocity, acceleration, deceleration, MAX_PROFILE_VELOCITY, c_velocity_ctrl);

        target_velocity = 0;                // rpm
        set_profile_velocity( target_velocity, acceleration, deceleration, MAX_PROFILE_VELOCITY, c_velocity_ctrl);
	}
}

int main(void)
{
	// Motor control channels
	chan c_qei_p1, c_qei_p2, c_qei_p3, c_qei_p4, c_qei_p5, c_hall_p6, c_qei_p6;		// qei channels
	chan c_hall_p1, c_hall_p2, c_hall_p3, c_hall_p4, c_hall_p5;				// hall channels
	chan c_commutation_p1, c_commutation_p2, c_commutation_p3, c_signal;	// commutation channels
	chan c_pwm_ctrl, c_adctrig;												// pwm channels
	chan c_velocity_ctrl;													// velocity control channel
	chan c_watchdog; 														// watchdog channel

	par
	{

		/* Test Profile Velocity function */
		on tile[0]:
		{
			profile_velocity_test(c_velocity_ctrl);			// test PVM on node
		//	velocity_ctrl_unit_test(c_velocity_ctrl, c_qei_p3, c_hall_p3);
		}

		on tile[2]:
		{

			/* Velocity Control Loop */
			{
				ctrl_par velocity_ctrl_params;
				filter_par sensor_filter_params;
				hall_par hall_params;
				qei_par qei_params;

				/* Initialize PID parameters for Velocity Control (defined in config/motor/bldc_motor_config.h) */
				init_velocity_control_param(velocity_ctrl_params);

				/* Initialize Sensor configuration parameters (defined in config/motor/bldc_motor_config.h) */
				init_hall_param(hall_params);
				init_qei_param(qei_params);

				/* Initialize sensor filter length */
				init_sensor_filter_param(sensor_filter_params);

				/* Control Loop */
				velocity_control(velocity_ctrl_params, sensor_filter_params, hall_params, \
					 qei_params, SENSOR_USED, c_hall_p2, c_qei_p2, c_velocity_ctrl, c_commutation_p2);
			}

		}

		/************************************************************
		 * IFM_CORE
		 ************************************************************/
		on tile[IFM_TILE]:
		{
			par
			{
				/* PWM Loop */
				do_pwm_inv_triggered(c_pwm_ctrl, c_adctrig, p_ifm_dummy_port,\
						p_ifm_motor_hi, p_ifm_motor_lo, clk_pwm);

				/* Motor Commutation loop */
				{
					hall_par hall_params;
					qei_par qei_params;
					commutation_par commutation_params;
					int init_state;
					init_hall_param(hall_params);
					init_qei_param(qei_params);
					commutation_sinusoidal(c_hall_p1,  c_qei_p1, c_signal, c_watchdog, 	\
							c_commutation_p1, c_commutation_p2, c_commutation_p3, c_pwm_ctrl,\
							p_ifm_esf_rstn_pwml_pwmh, p_ifm_coastn, p_ifm_ff1, p_ifm_ff2,\
							hall_params, qei_params, commutation_params);
				}

				/* Watchdog Server */
				run_watchdog(c_watchdog, p_ifm_wd_tick, p_ifm_shared_leds_wden);

				/* Hall Server */

				{
					hall_par hall_params;
					run_hall(c_hall_p1, c_hall_p2, c_hall_p3, c_hall_p4, c_hall_p5, c_hall_p6, p_ifm_hall, hall_params); // channel priority 1,2..5
				}

				/* QEI Server */

				{
					qei_par qei_params;
					init_qei_param(qei_params);
					run_qei(c_qei_p1, c_qei_p2, c_qei_p3, c_qei_p4, c_qei_p5, c_qei_p6, p_ifm_encoder, qei_params);  		 // channel priority 1,2..5
				}

			}
		}

	}

	return 0;
}
