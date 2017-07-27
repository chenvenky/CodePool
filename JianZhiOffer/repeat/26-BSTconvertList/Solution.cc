/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 21 Jul 2017 06:35:31 AM PDT
*
* Description: 
    二叉搜索树与双向链表： 递归    
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL; 
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree; 

        TreeNode* left = Convert(pRootOfTree->left); 
        TreeNode* right = Convert(pRootOfTree->right); 
        TreeNode* pos = left; 
        while(pos != NULL && pos->right != NULL)
            pos = pos->right; 
        if(left != NULL)
        {
            pos->right = pRootOfTree; 
            pRootOfTree->left = pos; 
        }
        if(right != NULL)
        {
            pRootOfTree->right = right; 
            right->left = pRootOfTree; 
        }

        if(left != NULL)
            return left; 
        else
            return pRootOfTree; 
    }
}; 

int main()
{

    return 0; 
}
