#ifndef __LWIP_T41__
#define __LWIP_T41__

#if defined(ARDUINO_TEENSY41)

#include "lwip/ip_addr.h"
#include "lwip/pbuf.h"
#include "lwipopts.h"

#ifdef __cplusplus
extern "C" {
#endif
   
typedef void (*rx_frame_fn)(void*);
typedef void (*tx_timestamp_fn)(uint32_t);

void enet_getmac(uint8_t *mac);
void enet_init(ip_addr_t *ip, ip_addr_t *mask, ip_addr_t *gw);
void enet_set_rx_callback(rx_frame_fn rx_cb);
void enet_set_tx_timestamp_callback(tx_timestamp_fn tx_cb);
struct pbuf* enet_rx_next();
void enet_input(struct pbuf* p_frame);
void enet_proc_input(void);
void enet_poll();
void enet_txTimestampNextPacket();
uint32_t read_1588_timer();
err_t t41_extra_netif_init(struct netif *netif);

#ifdef LWIP_DEBUG
typedef void (*debug_print_string_fn)(const char *msg);
void set_debug_print(debug_print_string_fn func);
#endif

#ifdef __cplusplus
}
#endif

#ifdef LWIP_DEBUG
void _printf(const char* format, ...);
#endif

#endif

#endif
