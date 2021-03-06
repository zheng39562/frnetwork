/**********************************************************
 *  \file frnet_define.h
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#ifndef _frnet_define_H
#define _frnet_define_H

#include <stdint.h>

typedef int32_t Socket;
typedef uint32_t Port;
typedef uint8_t Byte;

#define NET_DEBUG_P(msg, arg...) K_DEBUG_P(log_key(), msg, ##arg)
#define NET_DEBUG_D(msg, arg...) K_DEBUG_D(log_key(), msg, ##arg)
#define NET_DEBUG_I(msg, arg...) K_DEBUG_I(log_key(), msg, ##arg)
#define NET_DEBUG_W(msg, arg...) K_DEBUG_W(log_key(), msg, ##arg)
#define NET_DEBUG_E(msg, arg...) K_DEBUG_E(log_key(), msg, ##arg)
#define NET_DEBUG_C(msg, arg...) K_DEBUG_C(log_key(), msg, ##arg)

#endif 

