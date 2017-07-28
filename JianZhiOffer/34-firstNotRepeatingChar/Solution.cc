/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 28 Jul 2017 07:05:58 AM PDT
*
* Description: 
    第一次只出现一次的字符。     
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
    int FirstNotRepeatingChar(string str)
    {
        if(str.size() == 0)
            return -1; 

        int dict[256] = {0}; 
        for(int i = 0; i < str.size(); i++)
            dict[str[i]]++; 
        for(int i = 0; i < str.size(); i++)
            if(dict[str[i]] == 1)
                return i; 

        return -1; 
    }
}; 

int main()
{

    return 0; 
}
