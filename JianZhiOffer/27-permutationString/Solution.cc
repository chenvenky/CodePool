/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 27 Jul 2017 06:29:08 AM PDT
*
* Description: 
    字符串的排列： 递归，回溯法。     
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
    vector<string> Permutation(string str)
    {
        vector<string> res; 
        if(str == "")
            return res; 

        solvePermutation(str, 0, res); 
        
        return res; 
    }
private:
    void solvePermutation(string str, int k, vector<string>& res)
    {
        if(k == (str.size() - 1))
        {
            res.push_back(str); 
            return; 
        }

        sort(str.begin() + k, str.end()); 
        unordered_set<char> ch; 
        for(int i = k; i < str.size(); i++)
        {
            if(ch.find(str[i]) == ch.end())
            {
                ch.insert(str[i]); 
                swap(str[k], str[i]); 
                solvePermutation(str, k + 1, res); 
                swap(str[k], str[i]); 
            }
        }
    }
}; 

int main()
{

    return 0; 
}
