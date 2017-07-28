/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 28 Jul 2017 06:49:12 AM PDT
*
* Description: 
    丑数： 动态规划。     
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
    int GetUglyNumber_Solution(int index)
    {
        if(index <= 0)
            return 0; 

        vector<int> ugly(index, 0); 
        ugly[0] = 1; 

        int f2 = 0, f3 = 0, f5 = 0; 
        for(int i = 1; i < index; i++)
        {
            ugly[i] = min(ugly[f2] * 2, min(ugly[f3] * 3, ugly[f5] * 5)); 
            if(ugly[i] == ugly[f2] * 2)
                f2++; 
            if(ugly[i] == ugly[f3] * 3)
                f3++; 
            if(ugly[i] == ugly[f5] * 5)
                f5++; 
        }

        return ugly[index - 1]; 
    }
}; 

int main()
{

    return 0; 
}
