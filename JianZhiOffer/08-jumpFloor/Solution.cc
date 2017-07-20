/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Tue 18 Jul 2017 07:35:00 AM PDT
*
* Description: 
    跳台阶： 递推， fibonacci    
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
    int jumpFloor(int number)
    {
        if(number < 0)
            throw runtime_error("Invalid Parameter"); 
        if(number <= 3)
            return number; 

        int fib1 = 2, fib2 = 3; 
        for(int i = 4; i <= number; i++)
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
