/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Mon 28 Aug 2017 01:17:18 AM PDT
*
* Description: 
    整数中　1 出现的次数。找规律    
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
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0; 
        int k = n; 
        for(int i = 1; (k = n / i); i *= 10)
        {
            cnt += (k / 10) * i; 
            int cur = k % 10; 
            if(cur > 1)
            {
                cur += i; 
            }
            else if(cur == 1)
            {
                cnt += n - i * k + 1; 
            }
        }

        return cnt; 
    }
}; 

int main()
{

    return 0; 
}
