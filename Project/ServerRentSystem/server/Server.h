#ifndef __SERVER_H__
#define __SERVER_H__

#include "ServerSocket.h"
#include "StoreThread.h"

class Server
{
public:
   Server(LogDao& dao, std::string const& ip, const short port);
   ~Server();
   void dataMine(void);     // 启动服务器数据采集

protected:
private:
   ServerSocket m_socket;   // 接收客户端数据线程 
   StoreThread m_store;     // 存储线程


};

#endif  // __SERVER_H__
