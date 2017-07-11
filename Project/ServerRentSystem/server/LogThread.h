#ifndef __LOGTHREAD_H__
#define __LOGTHREAD_H__

#include "data.h"

class LogThread
{
public:
   virtual ~LogThread();
   void start() throw(ThreadException);                // 创建并启动线程
   static void* task(void*);        // 创建线程所需要的  static 函数
   virtual void run() = 0;          // 提供给派生类的线程处理函数接口
};

#endif      // __LOGTHREAD_H__
