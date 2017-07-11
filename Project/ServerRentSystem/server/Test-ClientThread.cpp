/*************************************************************************
* File Name: Test-ClientThread.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 10 Jul 2017 07:23:08 AM PDT
*
* Description: 
    
 ************************************************************************/

#include "ClientThread.h"
using namespace std; 

int main()
{
    int i = 0;
    while(1)
    {
        sleep(2);
        (new ClientThread(++i))->start(); 
    }
    pthread_exit(0); 
    return 0;
}
