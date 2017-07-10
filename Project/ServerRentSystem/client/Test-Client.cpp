/*************************************************************************
* File Name: Test-Client.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 10 Jul 2017 01:45:04 AM PDT
*
* Description: 
    
 ************************************************************************/

#include "Client.h"
#include "LogSender.h"
#include "LogReader.h"
#include "SocketSender.h"

int main()
{
    string logFile = "wtmpx"; 
    string loginsFile = "loginsFile"; 
    string failFile = "failFile"; 

    string Ip = "127.0.1.1"; 
    int port = 8000; 

    LogReader reader(logFile, loginsFile, failFile); 
    SocketSender sender(failFile, Ip, port); 

    Client Mycli(reader, sender); 
    try{

        Mycli.dataMine(); 
    }catch(ClientException& e)
    {
        cout << e.what() << endl; 
    }

    return 0; 
}
