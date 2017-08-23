/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 23 Aug 2017 06:32:31 AM PDT
*
* Description: 
    对称的二叉树：　递归    
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true; 

        return symmetrical(pRoot->left, pRoot->right); 
    }

private:
    bool symmetrical(TreeNode* lhs, TreeNode* rhs)
    {
        if(lhs == NULL && rhs == NULL)
            return true; 
        if(lhs == NULL || rhs == NULL)
            return false; 
        if(lhs->val != rhs->val)
            return false; 

        return (symmetrical(lhs->left, rhs->right) && symmetrical(lhs->right, rhs->left)); 
    }
}; 

int main()
{

    return 0; 
}
