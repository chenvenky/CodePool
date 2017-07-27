/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 27 Jul 2017 07:57:17 AM PDT
*
* Description: 
    把数组排成最小的数： 机智的排序。     
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
#include <algorithm>
using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string str = ""; 
        if(numbers.size() == 0)
            return str; 

        sort(numbers.begin(), numbers.end(), cmp); 
        for(int i = 0; i < numbers.size(); i++)
        {
            str += to_string(numbers[i]); 
        }

        return str; 
    }
private:
    static bool cmp(int a, int b)
    {
        string A = to_string(a); 
        string B = to_string(b); 
        string tmp = A; 
        A += B; 
        B += tmp; 

        return A < B; 
    }
}; 

int main()
{

    return 0; 
}
