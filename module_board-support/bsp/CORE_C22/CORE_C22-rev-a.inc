/**************
 * Core-C22
 * Rev. A
 **************/

#pragma once

#include <xs1.h>
#include <platform.h>
#include <flash.h>

/* Standard Tile definitions for demo/test apps */
#define COM_TILE 0
#define APP_TILE 1
#define APP_TILE_1 1
#define APP_TILE_2 2
#define IFM_TILE 3

/* SPI port definitions */ 
on tile[COM_TILE]: fl_SPIPorts p_spi_flash = { PORT_SPI_MISO,
 								PORT_SPI_SS,
 								PORT_SPI_CLK,
 								PORT_SPI_MOSI,
 								XS1_CLKBLK_2 };
/* RGB LED */
on tile[APP_TILE_1]: out port p_core_leds[3] = { XS1_PORT_1M,   /* Red */
					   XS1_PORT_1L,   /* Green */
					   XS1_PORT_1K }; /* Blue */

