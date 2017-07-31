/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 31 Jul 2017 07:18:29 AM PDT
*
* Description: 
    数组中只出现一次的数字。     
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
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
    {
        int flag = data[0]; 
        for(int i = 1; i < data.size(); i++)
            flag ^= data[i]; 

        *num1 = flag; 
        *num2 = flag; 

        flag = flag - (flag & (flag-1)); 
        for(int i = 0; i < data.size(); i++)
        {
            if(flag & data[i])
                (*num1) ^= data[i]; 
            else
                (*num2) ^= data[i]; 
        }
    }
}; 

int main()
{

    return 0; 
}
