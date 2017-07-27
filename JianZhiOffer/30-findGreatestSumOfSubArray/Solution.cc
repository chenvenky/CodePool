/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 27 Jul 2017 07:38:12 AM PDT
*
* Description: 
    连续子数组的最大和。 动态规划    
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
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int tot = array[0]; 
        int bestTot = array[0]; 

        for(int i = 1; i < array.size(); i++)
        {
            if(tot < 0)
                tot = array[i]; 
            else
                tot += array[i]; 

            bestTot = max(bestTot, tot); 
        }

        return bestTot; 
    }
}; 

int main()
{

    return 0; 
}
