#include "lwipopts.h"

#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif

#ifdef _PROJECT_TEENSY_NTP_
#include "lwip_t41.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include "lwip/prot/ethernet.h"

//
// DEMO TO SEE IF THIS WORKS!
//
s32_t teensy_ntp_set_vlan(struct netif* netif, struct pbuf* p, const struct eth_addr* src, const struct eth_addr* dst, u16_t eth_type) {
  if (eth_type == ETHTYPE_IP) {
    struct ip_hdr *ip = (struct ip_hdr *)((uint8_t *)(p->payload) + SIZEOF_ETH_HDR);
    if (ip->_proto == IP_PROTO_UDP) {
      int udp_offset = (ip->_v_hl & 0x0f) << 2;
      struct udp_hdr *udp = (struct udp_hdr *)((uint8_t*)(p->payload) + SIZEOF_ETH_HDR + udp_offset);
//      if ((lwip_ntohs(udp->src) == 123) || (lwip_ntohs(udp->dest) == 123)) {
      if ((lwip_ntohs(udp->src) == 7) || (lwip_ntohs(udp->dest) == 7)) {
        return netif->tci | 0xe000;
      }
    }
  }
  return netif->tci;
}


#endif