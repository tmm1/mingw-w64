/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef IP_EXPORT_INCLUDED
#define IP_EXPORT_INCLUDED 1

typedef ULONG IPAddr;
typedef ULONG IPMask;
typedef ULONG IP_STATUS;

#include <in6addr.h>

typedef struct in6_addr IPv6Addr;

#include <inaddr.h>

typedef struct ip_option_information {
  UCHAR Ttl;
  UCHAR Tos;
  UCHAR Flags;
  UCHAR OptionsSize;
  PUCHAR OptionsData;
} IP_OPTION_INFORMATION,*PIP_OPTION_INFORMATION;

#ifdef _WIN64
typedef struct ip_option_information32 {
  UCHAR Ttl;
  UCHAR Tos;
  UCHAR Flags;
  UCHAR OptionsSize;
  UCHAR *OptionsData;
} IP_OPTION_INFORMATION32,*PIP_OPTION_INFORMATION32;
#endif

typedef struct icmp_echo_reply {
  IPAddr Address;
  ULONG Status;
  ULONG RoundTripTime;
  USHORT DataSize;
  USHORT Reserved;
  PVOID Data;
  struct ip_option_information Options;
} ICMP_ECHO_REPLY,*PICMP_ECHO_REPLY;

#ifdef _WIN64
typedef struct icmp_echo_reply32 {
  IPAddr Address;
  ULONG Status;
  ULONG RoundTripTime;
  USHORT DataSize;
  USHORT Reserved;
  VOID *Data;
  struct ip_option_information32 Options;
} ICMP_ECHO_REPLY32,*PICMP_ECHO_REPLY32;
#endif

typedef struct arp_send_reply {
  IPAddr DestAddress;
  IPAddr SrcAddress;
} ARP_SEND_REPLY,*PARP_SEND_REPLY;

typedef struct tcp_reserve_port_range {
  USHORT UpperRange;
  USHORT LowerRange;
} TCP_RESERVE_PORT_RANGE,*PTCP_RESERVE_PORT_RANGE;

#define MAX_ADAPTER_NAME 128

typedef struct _IP_ADAPTER_INDEX_MAP {
  ULONG Index;
  WCHAR Name[MAX_ADAPTER_NAME];
} IP_ADAPTER_INDEX_MAP,*PIP_ADAPTER_INDEX_MAP;

typedef struct _IP_INTERFACE_INFO {
  LONG NumAdapters;
  IP_ADAPTER_INDEX_MAP Adapter[1];
} IP_INTERFACE_INFO,*PIP_INTERFACE_INFO;

typedef struct _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS {
  ULONG NumAdapters;
  IPAddr Address[1];
} IP_UNIDIRECTIONAL_ADAPTER_ADDRESS,*PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS;

typedef struct _IP_ADAPTER_ORDER_MAP {
  ULONG NumAdapters;
  ULONG AdapterOrder[1];
} IP_ADAPTER_ORDER_MAP,*PIP_ADAPTER_ORDER_MAP;

typedef struct _IP_MCAST_COUNTER_INFO {
  ULONG64 InMcastOctets;
  ULONG64 OutMcastOctets;
  ULONG64 InMcastPkts;
  ULONG64 OutMcastPkts;
} IP_MCAST_COUNTER_INFO,*PIP_MCAST_COUNTER_INFO;

typedef struct _IPV6_ADDRESS_EX_LH {
  USHORT sin6_port;
  ULONG  sin6_flowinfo;
  USHORT sin6_addr[8];
  ULONG  sin6_scope_id;
} IPV6_ADDRESS_EX, *PIPV6_ADDRESS_EX;

#define IP_STATUS_BASE 11000

#define IP_SUCCESS 0
#define IP_BUF_TOO_SMALL (IP_STATUS_BASE + 1)
#define IP_DEST_NET_UNREACHABLE (IP_STATUS_BASE + 2)
#define IP_DEST_HOST_UNREACHABLE (IP_STATUS_BASE + 3)
#define IP_DEST_PROT_UNREACHABLE (IP_STATUS_BASE + 4)
#define IP_DEST_PORT_UNREACHABLE (IP_STATUS_BASE + 5)
#define IP_NO_RESOURCES (IP_STATUS_BASE + 6)
#define IP_BAD_OPTION (IP_STATUS_BASE + 7)
#define IP_HW_ERROR (IP_STATUS_BASE + 8)
#define IP_PACKET_TOO_BIG (IP_STATUS_BASE + 9)
#define IP_REQ_TIMED_OUT (IP_STATUS_BASE + 10)
#define IP_BAD_REQ (IP_STATUS_BASE + 11)
#define IP_BAD_ROUTE (IP_STATUS_BASE + 12)
#define IP_TTL_EXPIRED_TRANSIT (IP_STATUS_BASE + 13)
#define IP_TTL_EXPIRED_REASSEM (IP_STATUS_BASE + 14)
#define IP_PARAM_PROBLEM (IP_STATUS_BASE + 15)
#define IP_SOURCE_QUENCH (IP_STATUS_BASE + 16)
#define IP_OPTION_TOO_BIG (IP_STATUS_BASE + 17)
#define IP_BAD_DESTINATION (IP_STATUS_BASE + 18)

#define IP_DEST_NO_ROUTE (IP_STATUS_BASE + 2)
#define IP_DEST_ADDR_UNREACHABLE (IP_STATUS_BASE + 3)
#define IP_DEST_PROHIBITED (IP_STATUS_BASE + 4)
#define IP_DEST_PORT_UNREACHABLE (IP_STATUS_BASE + 5)
#define IP_HOP_LIMIT_EXCEEDED (IP_STATUS_BASE + 13)
#define IP_REASSEMBLY_TIME_EXCEEDED (IP_STATUS_BASE + 14)
#define IP_PARAMETER_PROBLEM (IP_STATUS_BASE + 15)

#define IP_DEST_UNREACHABLE (IP_STATUS_BASE + 40)
#define IP_TIME_EXCEEDED (IP_STATUS_BASE + 41)
#define IP_BAD_HEADER (IP_STATUS_BASE + 42)
#define IP_UNRECOGNIZED_NEXT_HEADER (IP_STATUS_BASE + 43)
#define IP_ICMP_ERROR (IP_STATUS_BASE + 44)
#define IP_DEST_SCOPE_MISMATCH (IP_STATUS_BASE + 45)

#define IP_ADDR_DELETED (IP_STATUS_BASE + 19)
#define IP_SPEC_MTU_CHANGE (IP_STATUS_BASE + 20)
#define IP_MTU_CHANGE (IP_STATUS_BASE + 21)
#define IP_UNLOAD (IP_STATUS_BASE + 22)
#define IP_ADDR_ADDED (IP_STATUS_BASE + 23)
#define IP_MEDIA_CONNECT (IP_STATUS_BASE + 24)
#define IP_MEDIA_DISCONNECT (IP_STATUS_BASE + 25)
#define IP_BIND_ADAPTER (IP_STATUS_BASE + 26)
#define IP_UNBIND_ADAPTER (IP_STATUS_BASE + 27)
#define IP_DEVICE_DOES_NOT_EXIST (IP_STATUS_BASE + 28)
#define IP_DUPLICATE_ADDRESS (IP_STATUS_BASE + 29)
#define IP_INTERFACE_METRIC_CHANGE (IP_STATUS_BASE + 30)
#define IP_RECONFIG_SECFLTR (IP_STATUS_BASE + 31)
#define IP_NEGOTIATING_IPSEC (IP_STATUS_BASE + 32)
#define IP_INTERFACE_WOL_CAPABILITY_CHANGE (IP_STATUS_BASE + 33)
#define IP_DUPLICATE_IPADD (IP_STATUS_BASE + 34)
#define IP_NO_FURTHER_SENDS (IP_STATUS_BASE + 35)

#define IP_GENERAL_FAILURE (IP_STATUS_BASE + 50)
#define MAX_IP_STATUS IP_GENERAL_FAILURE
#define IP_PENDING (IP_STATUS_BASE + 255)

#define IP_FLAG_DF 0x2

#define IP_OPT_EOL 0
#define IP_OPT_NOP 1
#define IP_OPT_SECURITY 0x82
#define IP_OPT_LSRR 0x83
#define IP_OPT_SSRR 0x89
#define IP_OPT_RR 0x7
#define IP_OPT_TS 0x44
#define IP_OPT_SID 0x88
#define IP_OPT_ROUTER_ALERT 0x94

#define MAX_OPT_SIZE 40

#ifdef CHICAGO

#define IOCTL_IP_RTCHANGE_NOTIFY_REQUEST 101
#define IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST 102
#define IOCTL_ARP_SEND_REQUEST 103
#define IOCTL_IP_INTERFACE_INFO 104
#define IOCTL_IP_GET_BEST_INTERFACE 105
#define IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS 106
#endif
#endif
