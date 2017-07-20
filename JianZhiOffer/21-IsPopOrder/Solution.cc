/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 06:29:32 AM PDT
*
* Description: 
    栈的压入， 弹出序列    
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
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if(pushV.size() != popV.size())
            return false; 

        stack<int> st; 
        int pos = 0; 
        for(int i = 0; i < pushV.size(); i++)
        {
            if(pushV[i] == popV[pos])
            {
                pos++; 
            }
            else
            {
                st.push(pushV[i]); 
            }

            while(!st.empty() && st.top() == popV[pos])
            {
                st.pop(); 
                pos++; 
            }
        }

        return (pos == popV.size()); 
    }
}; 

int main()
{

    return 0; 
}
