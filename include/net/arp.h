/*
 *  net/arp.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_ARP_H
#define _NET_ARP_H

#define	ARP_HADDR_LEN	6 		/* Size of Ethernet MAC address	*/
#define	ARP_PADDR_LEN	4		/* Size of IP address		*/

struct arphdr {
	unsigned short arp_hrd; 	/* format of hardware address	*/
	unsigned short arp_pro; 	/* format of protocol address	*/
	unsigned char  arp_hln; 	/* length of hardware address 	*/
	unsigned char  arp_pln; 	/* length of protocal address	*/
	unsigned short arp_op;  	/* arp/rarp operation		*/
	unsigned char  arp_sha[ARP_HADDR_LEN];
	unsigned char  arp_spa[ARP_PADDR_LEN];
	unsigned char  arp_tha[ARP_HADDR_LEN];
	unsigned char  arp_tpa[ARP_PADDR_LEN];
};

/* Values of arphdr->ah_hrd */
#define ARP_HTYPE_ETHER		1	/* Ethernet hardware type	*/

/* Values of arphdr->ah_pro */
#define ARP_PTYPE_IP		0x0800	/* IP protocol type		*/

/* Values of arphdr->ah_op  */
#define ARP_OP_REQUEST		1	/* Request op code		*/
#define ARP_OP_REPLY		2	/* Reply op code		*/

struct arpentry {
	struct aprentry *prev;
	struct aprentry *next;
	unsigned char mac[ARP_HADDR_LEN];
	unsigned char ip[ARP_PADDR_LEN];
};

#endif
