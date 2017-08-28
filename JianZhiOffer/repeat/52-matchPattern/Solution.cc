/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Fri 25 Aug 2017 11:36:17 PM PDT
*
* Description: 
    正则表达式匹配：　机智递归    
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
    bool match(char* str, char* pattern)
    {
        if(str == NULL && pattern == NULL)
            return true; 
        if(str == NULL || pattern == NULL)
            return false; 

        return solveMatch(str, pattern); 
    }

private:
    bool solveMatch(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true; 
        if(*str != '\0' && *pattern == '\0')
            return false; 

        if(*(pattern + 1) == '*')
        {
            if(*str == *pattern || (*pattern=='.' && *str!='\0'))
                return (solveMatch(str, pattern+2) || solveMatch(str+1, pattern));
            else
                return solveMatch(str, pattern+2); 
        }
        else if(*str == *pattern || (*pattern=='.' && *str!='\0'))
            return solveMatch(str+1, pattern+1); 

        return false; 
    }
}; 

int main()
{

    return 0; 
}
