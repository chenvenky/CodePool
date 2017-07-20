/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Tue 18 Jul 2017 07:50:20 AM PDT
*
* Description: 
    变态跳台阶： 递推， 解递推方程， 快速幂    
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
    int jumpFloorII(int num)
    {
        if(num < 0)
            throw runtime_error("Invalid Parameter"); 
        if(num == 0)
            return 0; 

        num -= 1; 
        int res = 1, base = 2; 
        while(num)
        {
            if(num & 1)
                res *= base; 
            base *= base; 
            num >>= 1; 
        }

        return res; 
    }
}; 

int main()
{

    return 0; 
}
