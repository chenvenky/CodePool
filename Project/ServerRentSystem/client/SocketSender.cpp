#include "SocketSender.h"


// 构造函数
SocketSender::SocketSender(std::string const& failFile, std::string const& ip, const short port):m_failFile(failFile), m_ip(ip), m_port(port), sockfd(-1)
{

}

// 析构函数 -- 关闭 TCP 连接
SocketSender::~SocketSender()
{
    close(sockfd); 
}


// 通过网络发送日志文件
// 1. 建立连接
// 2. 读取上次失败的日志记录
// 3. 通过网络发送日志记录给服务器
// 4. 保存发送失败的日志记录
void SocketSender::sendLog(list<MLogRec>& logs) throw(ClientException)
{
    connectServer(); 
    readFailFile(logs); 
    sendData(logs); 
    saveFailFile(logs); 
}


// 连接服务器
void SocketSender::connectServer(void) throw(SocketException)
{
   // 1. 获取 socket 描述符
   sockfd = socket(AF_INET, SOCK_STREAM, 0); 
   if(sockfd == -1) 
   {
        throw SocketException("获取 socket 描述错误"); 
   }

   // 2. 准备通信地址
   struct sockaddr_in server_addr; 
   server_addr.sin_family = AF_INET;    // 使用 ipv4地址
   server_addr.sin_addr.s_addr = inet_addr(m_ip.c_str()); 
   server_addr.sin_port = htons(m_port); 

   // 3. 连接服务器
   int ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
   if(ret == -1)
   {
       throw SocketException("连接服务器错误" + string(strerror(errno))); 
   }
}



// 读取上次发送失败的日志文件记录
void SocketSender::readFailFile(list<MLogRec>& logs) throw(ReadException)
{
    ifstream ifs(m_failFile.c_str()); 
    if(!ifs)
    {
        throw ReadException("File: " + m_failFile + " can't open"); 
    }

    MLogRec mrec; 
    while(ifs.peek() != EOF)
    {
        ifs >> mrec.logname >> mrec.logintime >> 
            mrec.logouttime >> mrec.durations >> mrec.logip;

        logs.push_back(mrec); 
    }

    ifs.close(); 
}


// 通过网络将容器中的数据发送给服务器
void SocketSender::sendData(list<MLogRec>& logs) throw(SendException)
{
     char buf[1024]; 

     while(logs.size())
     {
        MLogRec mrec = logs.front();  
        logs.pop_front();  
       
        strcpy(buf, "");         
        sprintf(buf, "%s %s", buf, mrec.logname); 
        sprintf(buf, "%s %d", buf, mrec.logintime); 
        sprintf(buf, "%s %d", buf, mrec.logouttime); 
        sprintf(buf, "%s %d", buf, mrec.durations); 
        sprintf(buf, "%s %s\t", buf, mrec.logip);    // Note: the last '\t' important
        int ret = send(sockfd, buf, strlen(buf), 0); 
        
        if(ret == -1)
        {
            saveFailFile(logs); 
            
            throw SendException(); 
            break; 
        }
     }
}


// 保存发送失败的日志记录
void SocketSender::saveFailFile(list<MLogRec>& log) throw(SaveException)
{
    ofstream ofs(m_failFile.c_str()); 
    if(!ofs)
    {
        throw SaveException("Can't save File" + m_failFile);
    }

    // Note: the format 
    for(list<MLogRec>::iterator it = log.begin(); it != log.end(); it++)
    {
        ofs << it->logname << " " << it->logintime << " " << it->logouttime << " "
            << it->durations << " " << it->logip << endl; 
    }
        
    ofs.close(); 
}

