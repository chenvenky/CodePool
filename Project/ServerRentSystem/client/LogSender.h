#ifndef __LOGSENDER_H__
#define __LOGSENDER_H__

#include "data.h"

using namespace std;

class LogSender
{
public:
   virtual ~LogSender();
   virtual void sendLog(list<MLogRec>& logs) = 0;   // 定义发送日志记录的接口

};

#endif  // __LOGSENDER_H__
