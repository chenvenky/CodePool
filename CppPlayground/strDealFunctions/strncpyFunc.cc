/*************************************************************************
* File Name: strncpyFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 12:24:15 PM CST
*
* Description: 
    strncpy
    注意：
        1. 给源字符加上 const 属性； 
        2. 给源地址和目的地址加上非零断言； 
        3. 为了实现链式操作，目的地址返回，而不是void; 
        4. 考虑源目的区域有重叠的情况。 
        5. 一定要保证复制完后，目的地址最后以空字符'\0'结尾。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
using namespace std;

char * Strncpy(char *destination, const char *source, int count)
{
    assert(destination != NULL && source != NULL); 
    assert(count > 0); 

    if(destination == source)
        return destination; 

    char *cp = destination; 
    while(count-- && *source != '\0')
        *cp++ = *source++; 
    *cp = '\0'; 

    return destination; 
}

int main()
{

    return 0; 
}
