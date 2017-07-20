/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 17 Jul 2017 08:00:59 AM PDT
*
* Description: 
    用两个栈实现队列。     
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
    void push(int node)
    {
        st2.push(node); 
    }

    int pop()
    {
        if(st1.empty())
        {
            while(!st2.empty())
            {
                st1.push(st2.top()); 
                st2.pop(); 
            }
        }
        if(st1.empty())
            throw runtime_error("pop on an empty queue"); 
        else
        {
            int res = st1.top(); 
            st1.pop(); 
            return res; 
        }
    }

private: 
    stack<int> st1; 
    stack<int> st2; 
}; 

int main()
{

    return 0; 
}
