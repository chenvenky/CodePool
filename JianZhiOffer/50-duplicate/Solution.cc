/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 07:44:36 AM PDT
*
* Description: 
    数组中重复的数字。　    
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
    bool duplicate(int numbers[], int length, int* duplication)
    {
        for(int i = 0; i < length; i++)
        {
            int tmp; 
            if(numbers[i] >= length)
                tmp = numbers[i] - length; 
            else
                tmp = numbers[i]; 

            if(numbers[tmp] >= length)
            {
                *duplication = tmp; 
                return true; 
            }
            else
                numbers[tmp] += length;
                 
        }

        return false; 
    }
};

int main()
{

    return 0; 
}
