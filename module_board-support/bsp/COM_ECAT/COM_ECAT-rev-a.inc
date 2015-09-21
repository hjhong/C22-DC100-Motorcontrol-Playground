/****************
 * COM EtherCAT
 * Rev. A
 ****************/

#pragma once

#include <xs1.h>
#include <platform.h>

#define PORT_ECAT_RST		on tile[COM_TILE]: XS1_PORT_1F
#define PORT_ECAT_IRQ		on tile[COM_TILE]: XS1_PORT_1I
#define PORT_ECAT_BUSY		on tile[COM_TILE]: XS1_PORT_1J
#define PORT_ECAT_WR		on tile[COM_TILE]: XS1_PORT_1K
#define PORT_ECAT_RD		on tile[COM_TILE]: XS1_PORT_1L
#define PORT_ECAT_CS		on tile[COM_TILE]: XS1_PORT_1M
#define PORT_ECAT_DATA		on tile[COM_TILE]: XS1_PORT_16A
#define PORT_ECAT_ADDRESS	on tile[COM_TILE]: XS1_PORT_16B

#define SOMANET_COM_ETHERCAT_PORTS {\
    PORT_ECAT_RST,		\
    PORT_ECAT_IRQ,		\
    PORT_ECAT_BUSY,		\
    PORT_ECAT_WR,		\
    PORT_ECAT_RD,		\
    PORT_ECAT_CS,		\
    PORT_ECAT_DATA,		\
    PORT_ECAT_ADDRESS	\
}
