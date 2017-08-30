/*************************************************************************
* File Name: memsetFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 01:04:53 PM CST
*
* Description: 
    memset    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void *Memset(void *str, int value, size_t count)
{
    if(str == NULL)
        return NULL; 

    void *p = str; 
    while(count--)
    {
        *(char*)p = (char)value; 
        p = (char *)p + 1; 
    }

    return str; 
}

int main()
{

    return 0; 
}
