/*************************************************************************
* File Name: memcpyFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 12:36:18 PM CST
*
* Description: 
    memcpy
        该函数不检查 source 结尾的 null 字符， 仅仅拷贝 count 个字节。 为了
        避免溢出， destination 和 source 指针所指的数组必须最少有 count 个
        字节， 而且两个区域不能重叠。 
        如果区域有重叠，那么要使用 memmove 这个更安全的方式。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cstdio>
using namespace std;

void *memcpy(void *destination, const void *source, size_t count)
{
    assert(destination != NULL && source != NULL); 

    void *address = destination; 
    while(count--)
    {
        *(char*)destination = *(char*)source; 
        destination = (char *)destination + 1; 
        source = (char *)source + 1; 
    }

    return address; 
}

int main()
{

    return 0; 
}
