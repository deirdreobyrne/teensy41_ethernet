#ifndef _LWIP_PROJECTS_HOOKS_H_
#define _LWIP_PROJECTS_HOOKS_H_

#define _PROJECT_TEENSY_NTP_

#include "lwip/prot/ethernet.h"
#include "lwip/netif.h"
#include "lwip/pbuf.h"

//#define LWIP_HOOK_VLAN_SET(netif,p,src,dst,eth_type) teensy_ntp_set_vlan(netif,p,src,dst,eth_type)

//#ifdef __cplusplus
//extern "C" {
//#endif
//s32_t teensy_ntp_set_vlan(struct netif* netif, struct pbuf* p, const struct eth_addr* src, const struct eth_addr* dst, u16_t eth_type);
//#ifdef __cplusplus
//}
//#endif

#endif
