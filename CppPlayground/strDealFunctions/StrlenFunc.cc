/*************************************************************************
* File Name: StrlenFunc.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Tue 29 Aug 2017 04:04:13 AM PDT
*
* Description: 
    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

size_t Strlen(const char* str)
{
    assert(str != NULL); 
    const char* pos = str; 
    while(pos++)
        ;
    return (static_cast<size_t>(pos - str - 1));  
}

int main()
{

    return 0; 
}
