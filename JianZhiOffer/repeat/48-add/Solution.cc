/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 16 Aug 2017 07:49:17 AM PDT
*
* Description: 
    不用加减乘除做加法： 异或，与
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
    int Add(int num1, int num2)
    {
        do
        {
            int tmp = num1 ^ num2; 
            num2 = num1 & num2; 
            num2 <<= 1; 
            num1 = tmp; 
        } while(num2); 

        return num1; 
    }
}; 

int main()
{

    return 0; 
}
