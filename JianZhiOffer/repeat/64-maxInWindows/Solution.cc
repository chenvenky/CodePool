/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Sat 22 Jul 2017 01:30:11 AM PDT
*
* Description: 
    滑动窗口的最大值。    
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

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res; 
        if(num.size() == 0 || size > num.size())
            return res; 
        
        deque<int> deq; 
        for(int i = 0; i < num.size(); i++)
        {
            while(!deq.empty() && (num[deq.back()] <= num[i]))
                  deq.pop_back();
            deq.push_back(i); 
            while(deq.front() + size <= i)
                  deq.pop_front(); 
                  
            if(i >= size - 1)
                  res.push_back(num[deq.front()]); 
        }

        return res; 
    }
};

int main()
{


    return 0; 
}
