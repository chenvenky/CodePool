/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 27 Jul 2017 07:05:24 AM PDT
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
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size() == 0)
            return 0; 

        int count = 1; 
        int res = numbers[0]; 
        for(int i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == res)
                count++; 
            else
                count--; 
            if(count == 0)
            {
                res = numbers[i]; 
                count = 1; 
            }
        }

        count = 0; 
        for(int i = 0; i < numbers.size(); i++)
        {
            if(res == numbers[i])
                count++; 
        }
        if(count * 2 > numbers.size())
            return res; 
        else 
            return 0; 
    }
}; 

int main()
{

    return 0; 
}
