/*************************************************************************
* File Name: Solution2.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 23 Aug 2017 05:26:18 AM PDT
*
* Description: 
    按之字形顺序打印二叉树：　双向队列进行模拟    
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
        if(pRoot == NULL)
            return res; 

        deque<TreeNode*> dq; 
        TreeNode* pos = pRoot; 
        dq.push_back(pos); 
        bool sign = false; 

        while(!dq.empty())
        {
            int sz = dq.size(); 
            sign = !sign; 
            vector<int> tmp;
             
            while(sz--)
            {
                if(sign)
                {
                    pos = dq.front(); 
                    dq.pop_front(); 
                    tmp.push_back(pos->val); 
                    if(pos->left != NULL)
                        dq.push_back(pos->left); 
                    if(pos->right != NULL)
                        dq.push_back(pos->right); 
                }
                else
                {
                    pos = dq.back(); 
                    dq.pop_back(); 
                    tmp.push_back(pos->val); 
                    if(pos->right != NULL)
                        dq.push_front(pos->right); 
                    if(pos->left != NULL)
                        dq.push_front(pos->left); 
                }
            }
            res.push_back(tmp); 
        }
        return res; 
    }
}; 

int main()
{

    return 0; 
}


