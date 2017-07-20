/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 05:48:30 AM PDT
*
* Description: 
    包含 min 函数的栈： pair<int, int>    
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
    void push(int value)
    {
        if(st.empty() || value <= st.top().second)
        {
            st.push(pair<int, int>(value, value)); 
        }
        else
        {
            st.push(pair<int, int>(value, st.top().second)); 
        }
    }

    void pop()
    {
        st.pop(); 
    }

    int top()
    {
        return st.top().first; 
    }

    int min()
    {
        return st.top().second; 
    }

private:
    stack<pair<int, int> > st; 
}; 

int main()
{

    return 0; 
}

