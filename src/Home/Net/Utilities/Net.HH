//Generic Networking definitions

#define ETHERNET_MIN_FRAME_SIZE		46
#define ETHERNET_MAC_HEADER_LENGTH	14
#define ETHERNET_ETHERTYPE_OFFSET	12
#define ETHERNET_DATA_OFFSET		14
#define MAC_ADDRESS_LENGTH			6
#define FCS_LENGTH					4

/*	Ethernet Frame Size.
	Based on IEEE 802.3 layer 1 Ethernet Max Frame is 1542 according to wiki. 72-1530 frame octet + 12 IPG octet
	Default: 1538 | Vlan: 1542 | Jumbo: 9038 | JumboVlan: 9042 */
#define ETHERNET_FRAME_SIZE     1542
  
// Max PayLoad standard: 1500 | Jumbo: 9000 for Gignet (fiber)
#define ETHERNET_v2_MTU 1500

#define HTYPE_ETHERNET	1
#define HLEN_ETHERNET	6
#define PLEN_IPV4		4

#define ETHERTYPE_IPV4	0x0800
#define ETHERTYPE_ARP	0x0806
#define ETHERTYPE_IPV6	0x86DD

#define IP_ADDRESS_LENGTH	4

/*	NICs reroute PCI interrupts to software. See $LK,"PCNet",A="FF:C:/Home/Net/Drivers/PCNet.ZC,irq = "$.
	Net Handler interrupt is generated whenever an entry is
	pushed to the NetQueue. See $LK,"NetHandler",A="FF:C:/Home/Net/Utilities/NetHandler.ZC,I_NETHANDLER"$. */

DefinePrint("I_NETHANDLER", "%d", IntEntryAlloc);

#define INT_DEST_CPU	0
