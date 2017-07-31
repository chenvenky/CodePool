/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 31 Jul 2017 07:59:58 AM PDT
*
* Description: 
    和为S的连续正数序列。 推导公式。    
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
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res; 
        for(int i = sqrt(2.0 * sum); i >= 2; i--)
        {
            int p = i; 
            int q = 2 * sum / p; 
            if(p * q != 2 * sum)
                continue; 
            
            int bigOne = p + q - 1; 
            if(bigOne & 1)
                continue; 
            int n = bigOne/2; 
            
            int smallOne = q - p + 1; 
            if(smallOne & 1)
                continue; 
            int m = smallOne / 2; 
            
            vector<int> tmp; 
            for(int j = m; j <= n; j++)
                tmp.push_back(j); 
            
            res.push_back(tmp); 
        }
        
        return res; 
    }
};

int main()
{

return 0; 
}

