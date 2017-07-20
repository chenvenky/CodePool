/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 06:56:50 AM PDT
*
* Description: 
    从上往下打印二叉树    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct TreeNode
{
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {

    }
}; 

class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> res; 
        if(root == NULL)
            return res; 

        TreeNode* pos = root; 
        queue<TreeNode*> qu; 
        qu.push(pos); 

        while(!qu.empty())
        {
            pos = qu.front(); 
            qu.pop(); 
            res.push_back(pos->val); 
            if(pos->left != NULL)
                qu.push(pos->left); 
            if(pos->right != NULL)
                qu.push(pos->right); 
        }

        return res; 
    }
}; 


int main()
{
    return 0; 
}
