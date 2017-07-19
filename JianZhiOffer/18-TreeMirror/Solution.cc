/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 07:51:27 AM PDT
*
* Description: 
    二叉树的镜像    
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
    struct TreeNode *left; 
    struct TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {

    }
}; 

class Solution
{
public:
    void Mirror(TreeNode *pRoot)
    {
        if(pRoot == NULL)
            return; 

        TreeNode* tmp = pRoot->left; 
        pRoot->left = pRoot->right; 
        pRoot->right = tmp; 
        Mirror(pRoot->left); 
        Mirror(pRoot->right); 

        return; 
    }
}; 

int main()
{

    return 0; 
}
