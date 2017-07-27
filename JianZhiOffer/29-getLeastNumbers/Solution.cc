/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 27 Jul 2017 07:23:05 AM PDT
*
* Description: 
    最小的 K 个数： 小根堆。     
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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res; 
        if(input.size() < k)
            return res; 

        priority_queue<int, vector<int>, greater<int>> smallHeap(input.begin(), input.end()); 
        while(k--)
        {
            res.push_back(smallHeap.top()); 
            smallHeap.pop(); 
        }

        return res; 
    }
}; 

int main()
{

    return 0; 
}
