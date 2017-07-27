/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Sat 22 Jul 2017 12:59:57 AM PDT
*
* Description: 
    数据流中的中位数： 大根堆，小根堆    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <queue>
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
    void Insert(int num)
    {
        bigHeap.push(num); 
        if(bigHeap.size() == smallHeap.size() + 1)
        {
            smallHeap.push(bigHeap.top()); 
            bigHeap.pop(); 
        }

        if(!bigHeap.empty() && bigHeap.top() > smallHeap.top())
        {
            bigHeap.push(smallHeap.top()); 
            smallHeap.pop(); 
            smallHeap.push(bigHeap.top()); 
            bigHeap.pop(); 
        }
    }

    double GetMedian()
    {
        if(smallHeap.size() > bigHeap.size())
        {
            return smallHeap.top(); 
        }
        else if(smallHeap.size() != 0)
        {
            return static_cast<double>(smallHeap.top() + bigHeap.top()) / 2.0; 
        }
        else
        {
            throw runtime_error("Try to get data from a empty queue"); 
        }
    }

private:
    priority_queue<int, vector<int>, less<int> > bigHeap; 
    priority_queue<int, vector<int>, greater<int> > smallHeap; 
}; 

int main()
{

    return 0; 
}
