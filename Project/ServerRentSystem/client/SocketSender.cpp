#include "SocketSender.h"


// 构造函数
SocketSender::SocketSender(std::string const& failFile, std::string const& ip, const short port, int sockfd)
{
   // TODO : implement
}

// 析构函数 -- 关闭 TCP 连接
SocketSender::~SocketSender()
{
   // TODO : implement
}

// 通过网络发送日志文件
void SocketSender::sendLog(list<MLogRec>& logs)
{
   // TODO : implement
}


// 连接服务器
void SocketSender::connectSever(void)
{
   // TODO : implement
}



// 读取上次发送失败的日志文件记录
void SocketSender::readFailFile(list<MLogRec>& logs)
{
   // TODO : implement
}


// 通过网络将容器中的数据发送给服务器
void SocketSender::sendData(list<MLogRec>& logs)
{
   // TODO : implement
}


// 保存发送失败的日志记录
void SocketSender::saveFailFile(list<MLogRec>& log)
{
   // TODO : implement
}
