/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Tue 18 Jul 2017 07:23:05 AM PDT
*
* Description: 
    斐波那契数列： 用两个变量模拟。     
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
    int Fibonacci(int n)
    {
        if(n < 0)
            throw runtime_error("Invalid Parameter"); 
        if(n == 0)
            return 0; 

        int fib1 = 1, fib2 = 1; 
        for(int i = 3; i <= n; i++)
        {
            int tmp = fib1; 
            fib1 = fib2; 
            fib2 += tmp; 
        }

        return fib2; 
    }
}; 

int main()
{

    return 0; 
}
