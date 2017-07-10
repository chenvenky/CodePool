#ifndef __SOCKETSENDER_H__
#define __SOCKETSENDER_H__


#include "LogSender.h"

class SocketSender : public LogSender
{
public:
   SocketSender(std::string const& failFile, std::string const& ip, const short port);
   ~SocketSender();
   virtual void sendLog(list<MLogRec>& logs);   // 通过网络发送日志记录

private:
   void connectServer(void);                     // 连接服务器
   void readFailFile(list<MLogRec>& logs);      // 读取上次失败的日志记录
   void sendData(list<MLogRec>& logs);          // 通过网络发送日志记录给服务器
   void saveFailFile(list<MLogRec>& log);       // 保存发送失败的日志记录

   const std::string m_failFile;      // 上次发送失败的已匹配记录的文件
   const std::string m_ip;            // 服务器进程 IP 
   const short m_port;          // 服务器进程端口
   int sockfd;                  // 套接字描述符
};

#endif  // __SOCKETSENDER_H__
