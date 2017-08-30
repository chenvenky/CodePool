/*************************************************************************
* File Name: IsBigEndian.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Sun 20 Aug 2017 08:09:57 PM CST
*
* Description: 
    判断机器是大端还是小端。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

void IsBigEndian(); 
int main()
{
    IsBigEndian(); 
    return 0; 
}

void IsBigEndian()
{
    union temp
    {
        short int a; 
        char b; 
    } temp; 
    temp.a = 0x1234; 
    if(temp.b == 0x34)
    {
        cout << "小端" << endl; 
    }
    else
    {
        cout << "大端" << endl; 
    }
}

