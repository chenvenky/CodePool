/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 09 Aug 2017 03:52:47 AM PDT
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
using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if(str.size() == 0)
            return str; 

        if(n > str.size())
            n %= str.size(); 

        reserveStr(str, 0, n-1); 
        reserveStr(str, n, str.size()-1); 
        reserveStr(str, 0, str.size()-1); 

        return str; 
    }

private:
    void reserveStr(string &str, int Left, int Right)
    {
        while(Left < Right)
        {
            char tmp = str[Left]; 
            str[Left] = str[Right]; 
            str[Right] = tmp; 
            Left++; 
            Right--; 
        }
    }
}; 

int main()
{

    return 0; 
}
