/*************************************************************************
* File Name: Solution2.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Mon 28 Aug 2017 01:09:51 AM PDT
*
* Description: 
    孩子们的游戏（圆圈中最后剩下的数）    
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
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1; 

        int last = 0; 
        for(int i = 2; i <= n; i++)
            last = (last + m) % i; 

        return last; 
    }
}; 

int main()
{

    return 0; 
}
