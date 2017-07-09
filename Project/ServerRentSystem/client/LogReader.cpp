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
    // TODO:

}


// 备份原始日志文件，并把新文件名存入 m_logFile
void LogReader::backup() throw (BackupException)
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
    if(ret == 1)
        throw BackupException("备份文件:" + m_logFile + " 异常");
    else if(ret == 2)
        throw BackupException("清空文件:" + m_logFile + "异常"); 
    
    m_logFile = m_logFile + "." + currentTime; 
}


// 读取上一次未匹配好的登录日志文件
void LogReader::readLoginsFile()
{
   // TODO : implement
   ifstream ifs(m_loginsFile.c_str()); 
   if(!ifs)
   {
       cout << "Can't open m_loginsFile" << endl; 
   }

   LogRec rec; 
   while(ifs)
   {
        ifs >> rec.logname >> rec.pid >> rec.type 
            >> rec.logtime >> rec.logip; 

         m_logins.push_back(rec); 
   }
   
   ifs.close(); 
}


// 读取备份日志文件
void LogReader::readBackFile()
{
    ifstream ifs(m_logFile.c_str(), ios::binary); 
    if(!ifs)
    {
        cout << "failed to open file wtmp" << endl;
        return; 
    }

    struct stat st; 
    stat(m_logFile.c_str(), &st); 
    // cout << "file size: " << st.st_size << endl; 
    int i; 
    for(i = 0; i < st.st_size / 372; i++)
    {
        LogRec rec; 

        ifs.seekg(i * 372, ios::beg); 
        ifs.read(rec.logname, sizeof(rec.logname)); 
        //cout << "name:\t" << rec.logname << endl; 
        if(rec.logname[0] == '.')   // ignore '.telnet'
            continue; 

        ifs.seekg(36, ios::cur); 
        ifs.read((char*)&rec.pid, sizeof(rec.pid)); 
        rec.pid = ntohl(rec.pid); 
        // cout << "pid:\t" << rec.pid << endl; 

        ifs.read((char*)&rec.type, sizeof(rec.type)); 
        rec.type = ntohs(rec.type); 
        //cout << "type:\t" << rec.type << endl; 

        ifs.seekg(6, ios::cur); 
        ifs.read((char*)&rec.logtime, sizeof(rec.logtime)); 
        rec.logtime = ntohl(rec.logtime); 
        //cout << "time:\t" << rec.logtime << endl; 

        ifs.seekg(30, ios::cur); 
        ifs.read(rec.logip, sizeof(rec.logip)); 
        // cout << "ip:\t" << rec.logip << endl; 

        if(rec.type == 7)
        {
            //m_logins.insert(m_logins.begin(), rec); 
            m_logins.push_back(rec); 
        }
        else if(rec.type == 8)
        {
            m_logouts.push_back(rec); 
        }
    } 

    ifs.close();        
}


// 匹配
void LogReader::match()
{
   // TODO : implement
}


// 保存本次未匹配的登入记录
void LogReader::saveLoginsFile()
{
   ofstream ofs(m_loginsFile.c_str()); 

   // Note: the format 
   for(list<LogRec>::iterator it = m_logins.begin(); it != m_logins.end(); it++)
   {
        ofs << it->logname << " " << it->pid << " " << it->type << " "
            << it->logtime << " " << it->logip << endl; 
   }

   ofs.close(); 
}
