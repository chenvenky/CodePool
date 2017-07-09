#include "LogReader.h"


// 构造函数
LogReader::LogReader(std::string const& logFile, std::string const& loginsFile, std::string const& failFile)
{
   m_logFile = logFile;
   m_loginsFile = loginsFile;
   m_failFile =failFile;
}


// 析构函数
LogReader::~LogReader()
{
   
}


/*
 * 1. 备份原始日志
 * 2. 读取上一次未匹配好的登录日志文件
 * 3. 读取备份日志文件
 * 4. 匹配
 * 5. 保存本次未匹配的登入记录
 */
list<MLogRec> LogReader::readLog()
{
    backup(); 
}


// 备份原始日志文件，并把新文件名存入 m_logFile
void LogReader::backup()
{
    // get current time
    time_t now_time = time(NULL); 
    char currentTime[64]; 
    strftime(currentTime, sizeof(currentTime), "%Y%m%d%H%M%S", localtime(&now_time)); 
    string cmd = ""; 
    cmd = cmd + "./backup.sh "+ m_logFile + " " + m_logFile + "." + currentTime; 
    int status = system(cmd.c_str()); 
    int ret = WEXITSTATUS(status); 
    // deal with exception   

}


// 读取上一次未匹配好的登录日志文件
void LogReader::readLoginsFile()
{
   // TODO : implement
}


// 读取备份日志文件
void LogReader::readBackFile()
{
   // TODO : implement
}


// 匹配
void LogReader::match()
{
   // TODO : implement
}


// 保存本次未匹配的登入记录
void LogReader::saveLoginsFile()
{
   // TODO : implement
}
