/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Sun 27 Aug 2017 02:16:06 AM PDT
*
* Description: 
    表示数值的字符串：　模拟。    
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
#include <cstring>
using namespace std;

class Solution
{
public:
    bool isNumeric(char *str)
    {
        bool hasE = false, sign = false, dot = false; 
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == 'e' || str[i] == 'E')
            {
                if(hasE || str[i+1] == '\0')
                    return false; 
                else
                    hasE = true; 
            }
            else if(str[i] == '+' || str[i] == '-')
            {
                if(str[i+1] == '\0')
                    return false; 
                if(sign && str[i-1] != 'e' && str[i-1] != 'E')
                    return false; 
                if(!sign && i != 0 && str[i-1] != 'e' && str[i-1] != 'E')
                    return false; 

                sign = true; 
            }
            else if(str[i] == '.')
            {
                if(dot || hasE)
                    return false; 
                if(str[i+1] == '\0')
                    return false; 

                dot = true; 
            }
            else if(str[i] < '0' || str[i] > '9')
                return false; 
        }

        return true; 
    }

}; 

int main()
{

    return 0; 
}
