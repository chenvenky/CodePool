/*************************************************************************
* File Name: Solution1.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Mon 28 Aug 2017 12:25:57 AM PDT
*
* Description: 
    孩子们的游戏。    
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
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1; 

        list<int> nums; 
        for(int i = 0; i < n; i++)
            nums.push_back(i); 

        auto item = nums.begin(); 
        while(nums.size() > 1)
        {
            for(int i = 1; i < m; i++)
            {
                item++; 
                if(item == nums.end())
                    item = nums.begin(); 
            }

            auto next = ++item; 
            if(next == nums.end())
                next = nums.begin(); 
            item--; 
            nums.erase(item); 
            item = next; 
        }

        return (*item); 
    }
}; 

int main()
{

    return 0; 
}
