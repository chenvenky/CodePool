/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 07:36:07 AM PDT
*
* Description: 
    树的子结构。    
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
    TreeNode(int x) : val(x), left(NULL), right(NULL){
    }
}; 

class Solution
{
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false; 
        
        return TreeEqueal(pRoot1, pRoot2) ||
            HasSubtree(pRoot1->left, pRoot2) || 
            HasSubtree(pRoot1->right, pRoot2); 
    }
private:
    bool TreeEqueal(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return true; 
        if(pRoot1 == NULL)
            return false; 

        if(pRoot1->val != pRoot2->val)
            return false; 

        return (TreeEqueal(pRoot1->left, pRoot2->left) && 
            TreeEqueal(pRoot1->right, pRoot2->right)); 
    }
}; 

int main()
{

    return 0; 
}
