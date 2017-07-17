/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 17 Jul 2017 06:28:05 AM PDT
*
* Description: 
    替换空格： 把字符串中的空格替换成 %20    
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
    void replaceSpace(char *str, int length)    // length 为目标字符串的最大长度
    {
        if(str == NULL || length <= 0)
            return; 

        int Len = 0; 
        int newLen = 0;
        int spaceCount = 0; 

        while(str[Len] != '\0')
        {
            if(str[Len] == ' ')
                spaceCount++; 
            Len++; 
        }

        newLen = Len + spaceCount * 2; 
        if(newLen > length)
        {
            throw logic_error("parameter: 'length' is too short!"); 
            return; 
        }

        while(Len >= 0 && newLen > Len)
        {
            if(str[Len] != ' ')
                str[newLen--] = str[Len--]; 
            else
            {
                str[newLen--] = '0'; 
                str[newLen--] = '2'; 
                str[newLen--] = '%'; 
                Len--; 
            }
        }
    }
}; 

int main()
{

    return 0; 
}
