#include "ConsoleSender.h"


ConsoleSender::ConsoleSender()
{
}


ConsoleSender::~ConsoleSender()
{
 
}


// 将已匹配的日志记录输出到控制台
void ConsoleSender::sendLog(list<MLogRec>& logs) throw()
{
    list<MLogRec>::iterator it = logs.begin(); 
    while(it != logs.end())
    {
        cout << it->logname << "\t" << it->logintime << 
        "\t" << it->logouttime << "\t" << it->durations << 
        "\t" << it->logip << endl; 

        it++; 
    }
}
