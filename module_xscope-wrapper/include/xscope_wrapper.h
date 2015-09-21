/**
 * @file xscope_wrapper.h
 * @author Synapticon GmbH <support@synapticon.com>
 */

#pragma once

/**
 * \def USE_XSCOPE
 * Enable all XScope related function calls when defined. This may be
 * added to CFLAGS in your project's Makefile: CFLAGS += -DUSE_XSCOPE
 */
#ifdef USE_XSCOPE

#include <xscope.h>

#else

/* replace xscope functions with NOPs */
#define xscope_register(...) while(0)
#define xscope_enable(...) while(0)
#define xscope_disable(...) while(0)
#define xscope_config_io(...) while(0)
#define xscope_ping(...) while(0)
#define xscope_char(...) while(0)
#define xscope_short(...) while(0)
#define xscope_int(...) while(0)
#define xscope_longlong(...) while(0)
#define xscope_float(...) while(0)
#define xscope_double(...) while(0)
#define xscope_bytes(...) while(0)
#define xscope_start(...) while(0)
#define xscope_stop(...) while(0)
#define xscope_start_int(...) while(0)
#define xscope_stop_int(...) while(0)
#define xscope_core_char(...) while(0)
#define xscope_core_short(...) while(0)
#define xscope_core_int(...) while(0)
#define xscope_core_longlong(...) while(0)
#define xscope_core_float(...) while(0)
#define xscope_core_double(...) while(0)
#define xscope_core_bytes(...) while(0)
#define xscope_core_start(...) while(0)
#define xscope_core_stop(...) while(0)
#define xscope_core_start_int(...) while(0)
#define xscope_core_stop_int(...) while(0)
#define xscope_data_from_host(...) while(0)
#define xscope_connect_data_from_host(...) while(0)

#define xscope_probe(...) while(0)
#define xscope_probe_data(...) while(0)
#define xscope_probe_data_pred(...) while(0)
#define xscope_probe_cpu(...) while(0)
#define xscope_probe_cpu_data(...) while(0)

#endif
