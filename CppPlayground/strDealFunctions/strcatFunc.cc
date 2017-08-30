/*************************************************************************
* File Name: strcatFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 01:11:45 PM CST
*
* Description: 
    strcat
    注意：
        1. 给源字符加上 const 属性
        2. 给目的地址加上非零断言
        3. 为了实现链式操作，将目的地址返回，而不是返回 void
        4. 考虑源目的区域有重叠的情况
        5. 一定要保证追加操作完后，目的地址最后以空字符'\0'结尾。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

char *Strcat(char *destination, const char *source)
{
    assert(destination != NULL && source != NULL); 
    char *cp = destination; 
    while(*cp)
        ++cp; 
    while(*cp++ = *source++)
        return destination; 
}

int main()
{
    return 0; 
}
