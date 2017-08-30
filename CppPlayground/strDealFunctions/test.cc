/*************************************************************************
* File Name: test.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 21 Aug 2017 11:13:17 AM CST
*
* Description: 
    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <cassert>
using namespace std;


int main()
{
    string str = "func"; 
    const char* str2="cute"; 

    cout << str.size() << endl; 
    cout << strlen(str2) << endl; 

    return 0; 
}
