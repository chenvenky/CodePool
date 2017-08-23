/*************************************************************************
* File Name: Solution1.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 23 Aug 2017 04:51:11 AM PDT
*
* Description: 
    按之字形顺序打印二叉树：记录偶数层逆序    
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
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> > res; 
        queue<TreeNode*> qu; 
        if(pRoot == NULL)
            return res; 

        TreeNode* pos = pRoot; 
        qu.push(pos); 
        bool sign = false; 
        while(!qu.empty())
        {
            int Len = qu.size(); 
            vector<int> tmp; 
            for(int i = 0; i < Len; i++)
            {
                pos = qu.front(); 
                qu.pop(); 
                tmp.push_back(pos->val); 
                if(pos->left != NULL)
                    qu.push(pos->left); 
                if(pos->right != NULL)
                    qu.push(pos->right); 
            }

            if(!sign)
            {
                res.push_back(tmp); 
            }
            else
            {
                reverse(tmp.begin(), tmp.end()); 
                res.push_back(tmp); 
            }

            sign = !sign; 
        }

        return res; 
    } 
}; 

int main()
{

    return 0; 
}
