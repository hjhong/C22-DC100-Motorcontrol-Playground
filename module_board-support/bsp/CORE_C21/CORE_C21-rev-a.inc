/**************
 * Core-C21-DX
 * Rev. A
 **************/

#pragma once

#include <xs1.h>
#include <platform.h>
#include <flash.h>

/* For single-node setups */
#define APP_TILE 0
#define IFM_TILE 1

/* SPI port definitions */ 
on tile[APP_TILE]: fl_SPIPorts p_spi_flash = { PORT_SPI_MISO,
 								PORT_SPI_SS,
 								PORT_SPI_CLK,
 								PORT_SPI_MOSI,
 								XS1_CLKBLK_2 };
/* RGB LED */
on tile[APP_TILE]: out port p_core_leds[3] = { XS1_PORT_1M,   /* Red */
					   XS1_PORT_1L,   /* Green */
					   XS1_PORT_1K }; /* Blue */