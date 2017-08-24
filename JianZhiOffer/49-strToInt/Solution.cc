/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 06:53:16 AM PDT
*
* Description: 
    把字符串转换成整数。模拟    
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
    int StrToInt(string str)
    {
        int ret = 0; 
        if(str.size() == 0)
            return ret; 
        bool sign = false; 
        int i = 0; 
        if(str[0] == '+')
            i++;
        else if(str[0] == '-')
        {
            i++;
            sign = true; 
        }

        for(; i < str.size(); i++)
        {
            ret *= 10;
            if(str[i]>='0' && str[i]<='9')
                ret += str[i] - '0'; 
            else
                return 0; 
        }

        if(sign)
            ret = -ret; 
        return ret; 
    }
}; 

int main()
{

    return 0; 
}
