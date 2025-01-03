#define TCP_MAX_PORT	65535

#define TCP_SRTT_ALPHA	0.9

// Transmission Time Out to prevent network slugglish performance
#define TCP_RTO_BETA	2
#define TCP_RTO_MIN		JIFFY_FREQ/5 // (linux TCP.H) should be using system timer/clock instead hardcoded
#define TCP_RTO_MAX		120*JIFFY_FREQ // JIFFY_FREZ = Hz. Hz is software clock ticks

#define TCP_MAX_WINDOW	32676	// Beyond this number, use window_scale(not implemented). 8192 is recommended/default.
U16 WINDOW_SIZE; 		// Initiate window size in CTPCPacketAllocate{} ?? Need more study
U16 RECEIVE_WINDOW; 		// gets host window size. It is not static.
U16 SEND_WINDOW; 		// gets receive window size from host, then adjust accordingly.

U32 RECEIVE_BUFFER; 		// is 32 too much? receive_buffer holds TCP data that has not yet been processed

#define TCP_MSS			536 // Max Segment Size default
#define TCP_MIN_MSS		88  // Min Segment Size

#define TCP_INIT_TIMEOUT	1*JIFFY_FREQ  // TODO... Init RTO Value. Not sure if this is needed.
#define TCP_TIMEOUT		20*JIFFY_FREQ // Roughly a minute based on software clock
#define TCP_KEEPALIVE		120*JIFFY_FREQ // TODO... 1 hour

#define TCP_MAX_INCREASEACK	16 //TODO... At Initial start up, it's generally slow. This accelerates the process.
#define TCP_MAX_DELAYACK	JIFFY_FREQ/5 //TODO... Delay max time ack
#define TCP_MIN_DELAYACK	JIFFY_FREQ/25 //TODO... Delay min time ack

#define TCP_STATE_CLOSED		0
#define TCP_STATE_LISTEN		1
#define TCP_STATE_SYN_SENT		2
#define TCP_STATE_SYN_RECEIVED	3
#define TCP_STATE_ESTABLISHED	4
#define TCP_STATE_FIN_WAIT1		5
#define TCP_STATE_FIN_WAIT2		6
#define TCP_STATE_CLOSE_WAIT	7
#define TCP_STATE_CLOSING		8
#define TCP_STATE_LAST_ACK		9
#define TCP_STATE_TIME_WAIT		10

// TCP header flags. Order of Operation matters. Test with Bt(), e.g. Bt(&flags, TCPf_RST)
#define TCPf_FIN	0
#define TCPf_SYN	1
#define TCPf_RST	2
//#define TCPf_PSH	3 // most stacks don't implement PUSH.
#define TCPf_ACK	4
//#define TCPf_URG	5 // most stacks don't implement URGENT.

#define TCPF_FIN	(1 << TCPf_FIN)
#define TCPF_SYN	(1 << TCPf_SYN)
#define TCPF_RST	(1 << TCPf_RST)
//#define TCPF_PSH	(1 << TCPf_PSH) // most stacks don't implement PUSH.
#define TCPF_ACK	(1 << TCPf_ACK)
//#define TCPF_URG	(1 << TCPf_URG) // most stacks don't implement URGENT.

// U32 TCP_MAX_DELAYACK(CSocket *Socket); // TODO 


class CTCPAckQueue:CQueue
{
	F64 time_sent;
	U32 retries;
	U32 start_seq_num;
	U32 end_seq_num;

	U32 tcp_packet_size;	// Size of memory allocation of U8* tcp_packet.
	U8 *tcp_packet;			// Memory location of entire TCP Header + Data Payload.
};

// stores packet data of incoming connect() requests,
// local accept() will search queue for pending connections,
// and use this data to send out notification connection was accepted.
class CTCPAcceptQueue:CQueue
{
	U32 segment_seq_num;
	U32 ipv4_address;
	U16 port;
};

class CTCPSocket
{
	CSocket					*socket;
	U8						 state;
	U64						 timeout; // timeout for socket calls. Initialized 0: non-blocking.

	CSocketAddressStorage	 source_address;	// based on ->family, cast or assign to a var as IPV4/IPV6 CSocketAddress
	CSocketAddressStorage	 destination_address;

	CTCPAckQueue			*ack_queue; // Sent TCP packets awaiting an ACK collect here to be retransmitted. CQueue head.

	U64						 accept_queue_limit;
	CTCPAcceptQueue			*accept_queue;

	U32						 max_segment_size;

	U32						 first_unacked_seq; // SEQ number of first unacknowledged octet
	U32						 next_send_seq_num;
	U32						 next_recv_seq_num;
	F64						 srtt; // Smoothed Round-Trip Time
	F64						 connection_time;

	U32						 receive_window;// allowed # of unacknowledged incoming octets
	U32						 send_window;	// allowed # of unacknowledged outgoing octets

	I64						 write_position; // position in RX buffer to write incoming octets
	I64						 read_position;  // position in RX buffer Socket calls have read up to
	I64						 receive_buffer_size;
	U8						*receive_buffer;
};


class CTCPTreeQueue:CQueue
{
	CTCPSocket		*socket;
};

class CTCPTreeNode:CBST
{
	CTCPTreeQueue	*queue;
};

class CTCPRepEntry:CQueue
{
	CTCPTreeNode *node;
};


class CTCPHeader
{
	U16	source_port;
	U16	destination_port;
	U32 seq_num;
	U32	ack_num;
	U8	data_offset;
	U8	flags;
	U16	window_size;
	U16	checksum;
	U16	urgent_pointer;
};

class CTCPPseudoHeader
{
	U32 source_address;
	U32 destination_address;
	U8	zeros;
	U8	protocol;
	U16	tcp_length; // length of TCP headers & payload
};

class CTCPGlobals
{

	CTCPTreeNode	*bound_socket_tree;
	U16				 next_source_port;

} tcp_globals;

