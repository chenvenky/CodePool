/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 09:56:56 PM PDT
*
* Description: 
    构建乘积数组。    
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
    vector<int> multiply(const vector<int>& A)
    {
        vector<int> res; 
        if(A.size() == 0)
            return res; 

        res.push_back(1); 
        for(int i = 0; i < A.size()-1; i++)
            res.push_back(res.back() * A[i]); 

        int tmp = 1; 
        for(int i = A.size()-1; i >= 0; i--)
        {
            res[i] *= tmp; 
            tmp *= A[i]; 
        }

        return res; 
    }
}; 

int main()
{

    return 0; 
}
