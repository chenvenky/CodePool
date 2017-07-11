#ifndef __CLIENTTHREAD_H__
#define __CLIENTTHREAD_H__

#include "LogThread.h"
#include "LogQueue.h"

class ClientThread : public LogThread
{
public:
   ClientThread(int accfd);     // 构造函数
   ~ClientThread();
   virtual void run(void);      // 接收客户端数据的线程处理函数, 存入存储队列

private:
   int m_accfd;     // 用于接收客户端数据的套接字描述符
};

#endif  // __CLIENTTHREAD_H__
