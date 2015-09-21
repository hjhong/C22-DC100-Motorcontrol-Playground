/****************
 * COM Ethernet
 * Rev. A
 ****************/

#pragma once

#include <xs1.h>
#include <platform.h>
 
/****************************************************************************/

#define ETHERNET_DEFAULT_TILE_P1 tile[0]
#define PORT_ETH_RST_N0 on tile[0]: XS1_PORT_1P;
#define PORT_ETH_RXCLK0 on tile[0]: XS1_PORT_1G
#define PORT_ETH_RXD0 on tile[0]: XS1_PORT_4E
#define PORT_ETH_TXD0 on tile[0]: XS1_PORT_4F
#define PORT_ETH_RXDV0 on tile[0]: XS1_PORT_1O
#define PORT_ETH_TXEN0 on tile[0]: XS1_PORT_1N
#define PORT_ETH_TXCLK0 on tile[0]: XS1_PORT_1I
#define PORT_ETH_MDIOC0 on tile[0]: XS1_PORT_4D
#define PORT_ETH_MDIOFAKE0 on tile[0]: XS1_PORT_8B
#define PORT_ETH_ERR0 on tile[0]: XS1_PORT_1M

#define ETHERNET_DEFAULT_TILE_P2 tile[0]
#define PORT_ETH_RST_N1 on tile[0]: XS1_PORT_1F;
#define PORT_ETH_RXCLK1 on tile[0]: XS1_PORT_1J
#define PORT_ETH_RXD1 on tile[0]: XS1_PORT_4B
#define PORT_ETH_TXD1 on tile[0]: XS1_PORT_4A
#define PORT_ETH_RXDV1 on tile[0]: XS1_PORT_1L
#define PORT_ETH_TXEN1 on tile[0]: XS1_PORT_1K
#define PORT_ETH_TXCLK1 on tile[0]: XS1_PORT_1H
#define PORT_ETH_MDIOC1 on tile[0]: XS1_PORT_4C
#define PORT_ETH_MDIOFAKE1 on tile[0]: XS1_PORT_8A
#define PORT_ETH_ERR1 on tile[0]: XS1_PORT_1E

/****************************************************************************/

#define ETHERNET_DEFAULT_PHY_ADDRESS 0
#define PORT_ETH_RST_N 1
#define SMI_COMBINE_MDC_MDIO 1
#define SMI_MDC_BIT 0
#define SMI_MDIO_BIT 1

#ifndef ETHERNET_DEFAULT_CLKBLK_0
#define ETHERNET_DEFAULT_CLKBLK_0 on ETHERNET_DEFAULT_TILE_P1: XS1_CLKBLK_1
#endif

#ifndef ETHERNET_DEFAULT_CLKBLK_1
#define ETHERNET_DEFAULT_CLKBLK_1 on ETHERNET_DEFAULT_TILE_P1: XS1_CLKBLK_3
#endif

#ifndef ETHERNET_DEFAULT_CLKBLK_2
#define ETHERNET_DEFAULT_CLKBLK_2 on ETHERNET_DEFAULT_TILE_P2: XS1_CLKBLK_4
#endif

#ifndef ETHERNET_DEFAULT_CLKBLK_3
#define ETHERNET_DEFAULT_CLKBLK_3 on ETHERNET_DEFAULT_TILE_P2: XS1_CLKBLK_5
#endif

#ifndef PORT_ETH_FAKE0
#define PORT_ETH_FAKE0 on ETHERNET_DEFAULT_TILE_P1: XS1_PORT_8C
#endif

#ifndef PORT_ETH_FAKE1
#define PORT_ETH_FAKE1 on ETHERNET_DEFAULT_TILE_P2: XS1_PORT_8D
#endif

#define ETHERNET_DEFAULT_MII_INIT_P1_lite { \
  ETHERNET_DEFAULT_CLKBLK_0, \
  ETHERNET_DEFAULT_CLKBLK_1, \
\
    PORT_ETH_RXCLK0,                             \
    PORT_ETH_ERR0,                               \
    PORT_ETH_RXD0,                               \
    PORT_ETH_RXDV0,                              \
    PORT_ETH_TXCLK0,                             \
    PORT_ETH_TXEN0,                              \
    PORT_ETH_TXD0,                               \
    PORT_ETH_FAKE0 \
}

#define ETHERNET_DEFAULT_MII_INIT_P2_lite { \
  ETHERNET_DEFAULT_CLKBLK_2, \
  ETHERNET_DEFAULT_CLKBLK_3, \
\
    PORT_ETH_RXCLK1,                             \
    PORT_ETH_ERR1,                               \
    PORT_ETH_RXD1,                               \
    PORT_ETH_RXDV1,                              \
    PORT_ETH_TXCLK1,                             \
    PORT_ETH_TXEN1,                              \
    PORT_ETH_TXD1,                               \
    PORT_ETH_FAKE1 \
}

#define ETHERNET_DEFAULT_MII_INIT_P1 ETHERNET_DEFAULT_MII_INIT_P1_lite
#define ETHERNET_DEFAULT_MII_INIT_P2 ETHERNET_DEFAULT_MII_INIT_P2_lite

#define ETHERNET_DEFAULT_SMI_INIT_P1 {ETHERNET_DEFAULT_PHY_ADDRESS, \
                                   PORT_ETH_MDIOC0}

#define ETHERNET_DEFAULT_SMI_INIT_P2 {ETHERNET_DEFAULT_PHY_ADDRESS, \
                                   PORT_ETH_MDIOC1}


