/*************************************************************************
* File Name: test.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 03:41:39 PM CST
*
* Description: 
    String 类测试文件    
 ************************************************************************/

#include <iostream>
#include <vector>
#include "String.h"
using namespace std;

void foo(String x)
{

}

void bar(const String& x)
{

}

String baz()
{
    String ret("world"); 
    return ret; 
}

int main()
{
    String s0; 
    String s1("hello"); 
    String s2(s0); 
    String s3 = s1; 
    s2 = s1; 

    foo(s1); 
    bar(s1); 
    foo("tmporary"); 
    bar("tmporary"); 
    String s4 = baz(); 

    std::vector<String> svec;
    svec.push_back(s0); 
    svec.push_back(s1); 
    svec.push_back(baz()); 
    svec.push_back("good job"); 
}
