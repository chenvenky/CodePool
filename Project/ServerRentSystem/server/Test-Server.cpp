/*************************************************************************
* File Name: Test-Server.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Tue 11 Jul 2017 12:37:42 AM PDT
*
* Description: 
    
 ************************************************************************/

#include "Server.h"

int main()
{
    // FileDao dao("dbFile"); 
	string user="system"; 
	string passwd="open123"; 

	OracleDao dao(user, passwd); 


    string Ip = "127.0.1.1"; 
    short port = 8000; 

    Server server(dao, Ip, port); 
    server.dataMine(); 

    return 0; 
}
