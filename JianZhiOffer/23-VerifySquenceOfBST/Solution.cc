/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 07:34:00 AM PDT
*
* Description: 
    二叉搜索树的后序遍历序列。     
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
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size() == 0)
            return false; 

        return solve(sequence); 
    }

private:
    bool solve(vector<int> &seq)
    {
        int len = seq.size(); 
        if(len == 0)
            return true; 
        if(len == 1)
            return true; 
        int root = seq[len - 1]; 
        int pos = 0; 
        for(pos = len - 2; pos >= 0; pos--)
        {
            if(seq[i] < root)
                break; 
        }
        for(int i = 0; i < pos; i++)
            if(seq[pos] >= root)
                return false; 
        vector<int> left(seq.begin(), seq.begin() + pos + 1); 
        vector<int> right(seq.begin() + pos + 1, seq.end() - 1); 

        return (solve(left) && solve(right)); 
    }
}; 

int main()
{

    return 0; 
}
