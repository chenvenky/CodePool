/*************************************************************************
* File Name: strncatFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 01:19:14 PM CST
*
* Description: 
    strncat
    注意：
        1. 给源字符加上 const 属性
        2. 给源地址和目的地址加非零断言
        3. 为了实现链式操作，将目的地址返回，而不是返回 void
        4. 考虑源目的区域有重叠的情况
        5. 一定要保证追加操作完成后，目的地址最后以空字符'\0'结尾。   
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

char* Strncat(char *destination, const char *source, size_t count)
{
    assert(destination != NULL && source != NULL); 
    assert(count > 0); 
    char *cp = destination; 
    while(*cp)
        ++cp; 
    while(count-- && *source != '\0')
        *cp++ = *source++; 
        *cp = '\0'; 

    return destination; 
}

int main()
{

    return 0; 
}
