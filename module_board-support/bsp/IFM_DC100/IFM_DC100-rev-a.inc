/***************************
 * IFM Drive DC-100
 * Rev. A
 ***************************/

#pragma once

#include <xs1.h>
#include <platform.h>

#define IFM_RESOLUTION 740

/* A4935 control ports */
on tile[IFM_TILE]: port p_ifm_coastn = XS1_PORT_1G;
on tile[IFM_TILE]: out port p_ifm_esf_rstn_pwml_pwmh = XS1_PORT_4F;
on tile[IFM_TILE]: port p_ifm_ff1 = XS1_PORT_1H;
on tile[IFM_TILE]: port p_ifm_ff2 = XS1_PORT_1I;

/* ADC */
on tile[IFM_TILE]: in buffered  port:32 p_ifm_adc_misoa = XS1_PORT_1D;
on tile[IFM_TILE]: in buffered  port:32 p_ifm_adc_misob = XS1_PORT_1C;
on tile[IFM_TILE]: buffered out port:32 p_ifm_adc_sclk_conv_mosib_mosia = XS1_PORT_4C;
on tile[IFM_TILE]: in           port p_ifm_dummy_port = XS1_PORT_16A; /* any unused port */

/* BLDC Motor */
on tile[IFM_TILE]: in  port p_ifm_hall = XS1_PORT_4E;
on tile[IFM_TILE]: buffered out port:32 p_ifm_motor_hi[3] = { XS1_PORT_1K,   /* Hi A */
							XS1_PORT_1O,   /* Hi B */
							XS1_PORT_1M }; /* Hi C */

on tile[IFM_TILE]: buffered out port:32 p_ifm_motor_lo[3] = { XS1_PORT_1L,   /* Lo A */
							  XS1_PORT_1P,   /* Lo B */
							  XS1_PORT_1N }; /* Lo C */

on tile[IFM_TILE]: in port p_ifm_encoder = XS1_PORT_4A; /* Encoder */

/* LEDs, Watchdog */
on tile[IFM_TILE]: out port p_ifm_shared_leds_wden = XS1_PORT_4B; /* BlueGreenRed_WDEN */
on tile[IFM_TILE]: out port p_ifm_wd_tick = XS1_PORT_1F; /* WatchdogTick */

/* Expansion Ports */
on tile[IFM_TILE]: port p_ifm_ext_d[4] ={ XS1_PORT_1A,
									  XS1_PORT_1E,
									  XS1_PORT_1J,
									  XS1_PORT_1B };
