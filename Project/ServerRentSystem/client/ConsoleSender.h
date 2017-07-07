#ifndef __CONSOLESENDER_H__
#define __CONSOLESENDER_H__

#include "LogSender.h"

class ConsoleSender : public LogSender
{
public:
   ConsoleSender();
   ~ConsoleSender();
   virtual void sendLog(list<MLogRec>& logs);   // 将日志记录输出到控制台
};

#endif  // __CONSOLESENDER_H__
