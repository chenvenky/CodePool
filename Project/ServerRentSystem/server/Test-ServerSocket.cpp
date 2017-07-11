/*************************************************************************
* File Name: Test-ServerSocket.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 10 Jul 2017 06:43:39 PM PDT
*
* Description: 
    
 ************************************************************************/
#include "ServerSocket.h"

 int main()
 {
     string Ip = "127.0.1.1"; 
     short port = 8000; 

     ServerSocket server(Ip, port); 
     server.acceptClient(); 

     return 0; 
 }
