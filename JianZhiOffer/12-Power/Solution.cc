/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 04:31:37 AM PDT
*
* Description: 
    数值的整数次方： 考虑完善，特别是 double == 的判断。     
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
    double Power(double base, int exp)
    {
        if(exp == 0)
            return 1.0; 
        if(base > -0.0000001 && base < 0.0000001)
            return 0.0; 
        if(exp < 0)
        {
            base = 1.0 / base; 
            exp *= -1; 
        }

        double res = 1.0; 
        while(exp)
        {
            if(exp & 1)
                res *= base; 
            base *= base; 
            exp >>= 1; 
        }

        return res; 
    }
}; 

int main()
{

    return 0; 
}
