#include "ServerSocket.h"

// 启动套接字监听线程
ServerSocket::ServerSocket(std::string const& ip, short port)
{
   // TODO : implement
}


ServerSocket::~ServerSocket()
{
   // TODO : implement
}

/*
 * 等待客户端的连接，如果客户端连接到达，创建客户端线程接收数据
 * (1). 创建接收客户端数据的线程
 * (2). 把数据写进 数据队列（全局变量， 单例模式）
 */
void ServerSocket::acceptClient(void)
{
   // TODO : implement
}
