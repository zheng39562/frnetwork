/**********************************************************
 *  \file frnet_interface.cpp
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#include "frnet_interface.h"

using namespace std;

// namespace frnet
namespace frnet{

// log config
std::string g_log_key_ = "network";
const std::string& log_key(){
	return g_log_key_;
}
void set_log_config(const std::string& log_key, frpublic::eLogLevel log_level){
	g_log_key_ = log_key;
	frpublic::SingleLogServer::GetInstance()->set_log_level(g_log_key_, log_level);
}


//====================================================================================================
NetInterface::NetInterface(NetListen* listen)
	:read_cache_size_(4 * 1024), 
	 write_cache_size_(4 * 1024),
	 listen_(listen)
{}

NetInterface::~NetInterface(){ }


//====================================================================================================
NetClient::NetClient(NetListen* listen)
	:NetInterface(listen)
{}

NetClient::~NetClient(){}


//====================================================================================================
NetServer::NetServer(NetListen* listen)
	:NetInterface(listen), 
	 max_listen_num_(65535),
	 work_thread_num_(4)
{}

NetServer::~NetServer(){} 

} // namespace frnet

// Network Creator : boost::asio
#ifdef __TCP_USE_ASIO

#include "frnet_tcp_asio.h"

// use boost::asio
#include "frnet_tcp_asio.h"

NetClient* CreateNetClient(frnet::NetListen* listen){ return NULL; }
NetServer* CreateNetServer(frnet::NetListen* listen){ return NULL; }

// Network Creator : code self(linux epoll.)
#elif __FRNET_EPOLL

#include "frnet_epoll.h"
frnet::NetClient* CreateNetClient(frnet::NetListen* listen){ return new frnet::NetClient_Epoll(listen); }
frnet::NetServer* CreateNetServer(frnet::NetListen* listen){ return new frnet::NetServer_Epoll(listen); }

// else
#else


NetClient* CreateNetClient(frnet::NetListen* listen){ return NULL; }
NetServer* CreateNetServer(frnet::NetListen* listen){ return NULL; }

#endif

