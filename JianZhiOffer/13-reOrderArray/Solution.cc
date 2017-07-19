/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 04:49:03 AM PDT
*
* Description: 
    调整数组顺序使奇数位于偶数前面。     
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
    void reOrderArray(vector<int> &array)
    {
        vector<int> ans; 

        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2)
                ans.push_back(array[i]); 
        }

        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 0)
                ans.push_back(array[i]); 
        }

        array.swap(ans); 
    }
}; 

int main()
{

    return 0; 
}
