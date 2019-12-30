/*
 * linux/arch/arm/drivers/char/serial-atomwide.c
 *
 * Copyright (c) 1996 Russell King.
 *
 * Changelog:
 *  02-05-1996	RMK	Created
 *  07-05-1996	RMK	Altered for greater number of cards.
 *  30-07-1996	RMK	Now uses generic card code.
 */

#define MY_CARD_LIST { MANU_ATOMWIDE, PROD_ATOMWIDE_3PSERIAL }
#define MY_NUMPORTS 3
#define MY_BAUD_BASE (7372800 / 16)
#define MY_INIT atomwide_serial_init
#define MY_BASE_ADDRESS(ec) \
	ecard_address ((ec), ECARD_IOC, ECARD_SLOW) + (0x2000 >> 2)
#define MY_PORT_ADDRESS(port,cardaddr) \
	((cardaddr) + 0x200 - (port) * 0x100)
#include "serial-card.c"
