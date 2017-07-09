#ifndef __LOGREADER_H__
#define __LOGREADER_H__

#include <iostream>
#include "data.h"

using namespace std;

class LogReader
{
public:
   LogReader(std::string const& logFile, std::string const& loginsFile, std::string const& failFile);
   ~LogReader();
   list<MLogRec> readLog();

private:
   void backup() throw (BackupException);               // 备份文件，并把新文件名放进 m_logFile 
   void readLoginsFile();       // 读取上一次没匹配好的登入日志记录  
   void readBackFile();         // 读取备份日志记录文件
   void match();                // 匹配
   void saveLoginsFile();       // 保存未匹配的登入记录

   std::string m_logFile;       // 存放原始日志记录
   std::string m_loginsFile;    // 存放未匹配的登入日志记录
   std::string m_failFile;      // 存放发送失败的匹配好的登录日志记录
   list<LogRec> m_logins;       // 登录日志记录队列
   list<LogRec> m_logouts;      // 登出日志记录队列
   list<MLogRec> m_logs;        // 匹配好的日志记录队列
};

#endif  // __LOGREADER_H__
