#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__
#include "ClientThread.h"

class ServerSocket
{
public:
   ServerSocket(std::string const& ip, short port);
   ~ServerSocket();
   void acceptClient(void);     // 等待客户端的连接，如果有客户端连接到达，
                                // 创建客户端线程接收数据

private:
   int m_sockfd;        // 建立网络连接需要的套接字


};

#endif      // __SERVERSOCKET_H__
