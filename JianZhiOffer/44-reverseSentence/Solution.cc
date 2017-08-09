/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 09 Aug 2017 04:18:51 AM PDT
*
* Description: 
    反转单词序列。    
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
    string ReverseSentence(string str)
    {
        string ret = ""; 
        string tmp = ""; 

        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                ret = ' ' + tmp + ret; 
                tmp = ""; 
            }
            else 
            {
                tmp += str[i]; 
            }
        }

        return (tmp+ret); 
    }
}; 

int main()
{

    return 0; 
}
