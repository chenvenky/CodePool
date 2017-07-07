#include "Server.h"


Server::Server(LogDao& dao, std::string const& ip, const short port):m_socket(ip, port),
    m_store(dao)
{
   // TODO : implement
}


Server::~Server()
{
   // TODO : implement
}

/*
 * 启动服务器端数据采集
 * (1). 启动接收客户端发送数据的线程
 * (2). 启动数据存储的线程（注意同步）
 */ 
void Server::dataMine(void)
{
   // TODO : implement
}
