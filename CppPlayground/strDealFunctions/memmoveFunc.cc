/*************************************************************************
* File Name: memmoveFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 12:44:41 PM CST
*
* Description: 
    和 memcpy 函数一样，该函数也不会检查 source 末尾的空字符 null, 仅仅拷贝
    count 个字节； 为了避免溢出， destination 和 source 指针所指的数组必须
    最少有 count 个字节。 但是该函数允许源和目的区域重叠。 

 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

void *Memmove(void *destination, const void *source, size_t count)
{
    assert(destination != NULL && source != NULL); 

    char *pdest = (char*)destination; 
    char *psrc = (char*)source; 
    // pdest 在 psrc 后面， 且两者距离小于 count, 从尾部开始移动， 
    // 其他情况从头部开始移动
    if((pdest > psrc) && (pdest - psrc < count))
    {
        while(count--)
            *(pdest + count) = *(psrc + count); 
    }
    else
    {
        while(count--)
            *pdest++ = *psrc++; 
    }

    return destination; 
}

int main()
{

    return 0; 
}
