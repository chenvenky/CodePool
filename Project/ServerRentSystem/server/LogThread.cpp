#include "LogThread.h"

LogThread::~LogThread()
{
   // TODO : implement
}

// 创建并启动线程
void LogThread::start()
{
    pthread_t tid; 
   int ret = pthread_create(&tid, NULL, task, this); 
   if(ret == -1)
   {
       // throw ThreadException("Failed to create thread"); 
   }
}


// 包装 线程处理函数的静态函数
void* LogThread::task(void* arg)
{
    pthread_detach(pthread_self());     // detach thread
    static_cast<LogThread*>(arg)->run();
//    pthread_exit(0);  
    return NULL; 
}



