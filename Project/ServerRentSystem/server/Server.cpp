#include "Server.h"


Server::Server(LogDao& dao, std::string const& ip, const short port):m_socket(ip, port), m_store(dao)
{

}


Server::~Server()
{

}

/*
 * 启动服务器端数据采集
 * (1). 启动数据存储的线程（注意同步）
 * (2). 启动接收客户端发送数据的线程
 */ 
void Server::dataMine(void) throw(ServerException)
{

    m_store.start(); 
    printf("数据存储线程已启动!\n"); 
    m_socket.acceptClient();  
}
