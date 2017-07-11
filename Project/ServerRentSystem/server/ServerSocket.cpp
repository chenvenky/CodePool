#include "ServerSocket.h"

// 启动套接字监听线程
ServerSocket::ServerSocket(std::string const& ip, short port) throw(SocketException)
{
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(m_sockfd == -1)
    {
        throw SocketException("无法生成监听套接字： " + string(strerror(errno))); 
    }

    struct sockaddr_in server_addr; 
    server_addr.sin_family = AF_INET;   // 使用 ipv4 地址
    
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());   // 具体的 ip 地址 

    server_addr.sin_port = htons(port);

    // 3. bind 通信地址
    int ret = bind(m_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
    if(ret == -1)
    {
        throw SocketException("绑定IP和端口失败：" + string(strerror(errno)));
    }

    // 4. 监听
    listen(m_sockfd, 1024); 
     
}



ServerSocket::~ServerSocket()
{
   close(m_sockfd); 
}

/*
 * 等待客户端的连接，如果客户端连接到达，创建客户端线程接收数据
 * (1). 创建接收客户端数据的线程
 * (2). 把数据写进 数据队列（全局变量， 单例模式）
 */
void ServerSocket::acceptClient(void) throw(SocketException)
{
    while(1)
    {
        struct sockaddr_in client_addr; 
        socklen_t len = sizeof(client_addr); 
        int accfd = accept(m_sockfd, (struct sockaddr*)&client_addr, &len); 
        if(accfd == -1)
        {
            throw SocketException("server accept failed"); 
            return; 
        }
        (new ClientThread(accfd))->start(); 
    }
}
