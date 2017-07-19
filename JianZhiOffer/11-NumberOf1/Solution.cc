/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 04:20:15 AM PDT
*
* Description: 
    二进制中 1 的个数： 位运算    
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
    int NumberOf1(int n)
    {
        int count = 0; 
        while(n)
        {
            n &= n - 1; 
            count++; 
        }

        return count; 
    }
}; 

int main()
{

    return 0; 
}
