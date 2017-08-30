/*************************************************************************
* File Name: strlenFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 11:01:06 AM CST
*
* Description: 
    实现字符串处理函数， strlen.     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

size_t Strlen(const char *str)
{
    assert(str != NULL); 
    const char *end = str; 
    while(*end++)
        ;
        return (static_cast<size_t>(end - str - 1)); 
}

int main()
{
    char str[10] = "cute"; 
    cout << Strlen(str) << endl; 
    return 0; 
}
