/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 31 Jul 2017 08:19:35 AM PDT
*
* Description: 
    和为 S 的两个数字。     
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
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int left = 0; 
        int right = array.size() - 1; 
        vector<int> res; 
        while(left < right)
        {
            if(array[left] + array[right] == sum)
            {
                res.push_back(array[left]); 
                res.push_back(array[right]); 
                return res; 
            }
            while(array[left] + array[right] > sum)
                right--; 
            while(array[left] + array[right] < sum)
                left++; 
        }

        return res; 
    }
}; 

int main()
{

    return 0; 
}
