/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Tue 22 Aug 2017 08:04:38 AM PDT
*
* Description: 
    把二叉树打印成多行：　二叉树层次遍历    
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
    TreeNode(int val) : left(NULL), right(NULL){

    }
}; 

class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int>> res; 
        if(pRoot == NULL)
            return res; 

        TreeNode* pos = pRoot; 
        queue<TreeNode*> qu; 
        qu.push(pos); 
        while(!qu.empty())
        {
            int Len = qu.size(); 
            vector<int> tmp; 
            while(Len--)
            {
                pos = qu.front(); 
                qu.pop(); 
                tmp.push_back(pos->val); 
                if(pos->left != NULL)
                    qu.push(pos->left); 
                if(pos->right != NULL)
                    qu.push(pos->right); 
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
