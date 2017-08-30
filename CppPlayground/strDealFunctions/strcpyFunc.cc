/*************************************************************************
* File Name: strcpyFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 12:07:15 PM CST
*
* Description: 
    strcpy 函数实现：
    注意：
        1. 给源字符加上 const 属性
        2. 给源地址和目的地址加非零断言
        3. 为了实现链式操作，将目的地址返回，而不是返回 void. 
        4. 考虑源目的区域有重叠的情况。 
        5. 一定要保证复制后， 目的地址最后以空字符 '\0' 结尾。 
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

char *Strcpy(char *destination, const char *source)
{
    assert(destination != NULL && source != NULL); 

    if(destination == source)
        return destination; 

    char *cp = destination; 
    while((*cp++ = *source++) != '\0')
        ;
    return destination; 
}

int main()
{
    const char *src = "talk is cheap, show me the code."; 
    char dst[100]; 
    Strcpy(dst, src); 
    printf("%s\n", dst); 

    return 0; 
}
