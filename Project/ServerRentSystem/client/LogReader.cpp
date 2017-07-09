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
    readLoginsFile();
    readBackFile(); 
    match(); 
    saveLoginsFile(); 
    return m_logs;  
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
void LogReader::readLoginsFile() throw(ReadException)
{
   ifstream ifs(m_loginsFile);
   cout << m_loginsFile << endl;  
   if(!ifs)
   {
       throw ReadException("File: " + m_loginsFile + "can't open"); 
   }

   LogRec rec; 
   while(ifs.peek() != EOF)     // Note: don't use --> !ifs.eof()
   {
        ifs >> rec.logname >> rec.pid >> rec.type 
            >> rec.logtime >> rec.logip; 

         m_logins.push_back(rec); 
   }
   
   ifs.close(); 
}


// 读取备份日志文件
void LogReader::readBackFile() throw (ReadException)
{
    ifstream ifs(m_logFile, ios::binary); 
    if(!ifs)
    {
        throw ReadException("File: " + m_logFile + "can't open"); 
        return; 
    }

    struct stat st; 
    stat(m_logFile.c_str(), &st); 

    int i; 
    for(i = 0; i < st.st_size / 372; i++)
    {
        LogRec rec; 

        ifs.seekg(i * 372, ios::beg); 
        ifs.read(rec.logname, sizeof(rec.logname)); 

        if(rec.logname[0] == '.')   // ignore '.telnet'
            continue; 

        ifs.seekg(36, ios::cur); 
        ifs.read((char*)&rec.pid, sizeof(rec.pid)); 
        rec.pid = ntohl(rec.pid); 

        ifs.read((char*)&rec.type, sizeof(rec.type)); 
        rec.type = ntohs(rec.type); 

        ifs.seekg(6, ios::cur); 
        ifs.read((char*)&rec.logtime, sizeof(rec.logtime)); 
        rec.logtime = ntohl(rec.logtime); 

        ifs.seekg(30, ios::cur); 
        ifs.read(rec.logip, sizeof(rec.logip)); 

        if(rec.type == 7)
        {
            m_logins.push_back(rec); 
        }
        else if(rec.type == 8)
        {
            m_logouts.push_back(rec); 
        }

    } 
    
    // debug
    cout << "Login:\t" << m_logins.size() << endl; 
    cout << "Logout:\t" << m_logouts.size() << endl; 

    ifs.close();        
}


// 匹配
void LogReader::match()
{
   list<LogRec>::iterator InIter; 
   list<LogRec>::iterator OutIter; 

   while(m_logouts.size())
   {
       OutIter = m_logouts.begin(); 
       InIter = m_logins.begin(); 

       while(InIter != m_logins.end())
       {
            if((!strcmp(OutIter->logname, InIter->logname)) && 
               (OutIter->pid == InIter->pid) && 
               (!strcmp(OutIter->logip, InIter->logip))
              )
            {
                MLogRec rec; 
                strncpy(rec.logname, InIter->logname, sizeof(rec.logname)); 
                rec.logintime = InIter->logtime; 
                rec.logouttime = OutIter->logtime; 
                rec.durations = rec.logouttime - rec.logintime; 
                strncpy(rec.logip, InIter->logip, sizeof(rec.logip)); 
                
                m_logs.push_back(rec); 
                m_logouts.pop_front(); 
                m_logins.erase(InIter); 

                break;      
            }
            else
            {
                InIter++; 
                if(InIter == m_logins.end())
                {
                    m_logouts.pop_front(); 
                }
            }
       } 
   }

   // debug
   cout << "Login left:\t" << m_logins.size() << endl; 
}


// 保存本次未匹配的登入记录
void LogReader::saveLoginsFile() throw(SaveException)
{
   ofstream ofs(m_loginsFile);
   if(!ofs)
   {
        throw SaveException("Can't save File" + m_loginsFile); 
   } 

   // Note: the format 
   for(list<LogRec>::iterator it = m_logins.begin(); it != m_logins.end(); it++)
   {
        ofs << it->logname << " " << it->pid << " " << it->type << " "
            << it->logtime << " " << it->logip << endl; 
   }
   
   ofs.close(); 
}

// Test to debug
int main()
{
    string logFile = "wtmpx"; 
    string loginsFile = "loginsFile"; 
    string failFile = "failFile"; 
    LogReader reader(logFile, loginsFile, failFile); 

    list<MLogRec> res = reader.readLog(); 

    // dubug
    cout << "matched：\t" << res.size() << endl; 
    return 0;  
}
