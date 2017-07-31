/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 31 Jul 2017 06:38:23 AM PDT
*
* Description: 
    平衡二叉树。     
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
    TreeNode(int x): val(x), left(NULL), right(NULL)
    {

    }
}; 

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true; 

        int leftPath, rightPath; 
        int lSign = getPath(pRoot->left, leftPath); 
        int rSign = getPath(pRoot->right, rightPath); 
        if(abs(leftPath - rightPath) > 1)
            return false; 
        return (lSign && rSign); 
    }

private:
    bool getPath(TreeNode* pos, int &path)
    {
        if(pos == NULL)
        {
            path = 0; 
            return true; 
        }
        if(pos->left == NULL && pos->right == NULL)
        {
            path = 1; 
            return true; 
        }
        
        int leftPath, rightPath; 
        int lSign = getPath(pos->left, leftPath); 
        int rSign = getPath(pos->right, rightPath); 
        if(abs(leftPath - rightPath) > 1)
            return false; 

        path = max(leftPath, rightPath) + 1; 
        return (lSign && rSign);
    }
}; 

int main()
{
    return 0; 
}
