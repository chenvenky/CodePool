/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 08:07:06 AM PDT
*
* Description: 
    二叉树中和为某一值的路径。     
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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        if(root == NULL)
            return allRes; 

        dfs(root, expectNumber); 

        return allRes; 
    }

private:
    vector<vector<int> > allRes; 
    vector<int> tmp; 

    void dfs(TreeNode* root, int left)
    {
        tmp.push_back(root->val); 
        if(left == root->val && root->left == NULL && root->right == NULL)
            allRes.push_back(tmp); 
        
        if(root->left != NULL)
            dfs(root->left, left - root->val); 
        if(root->right != NULL)
            dfs(root->right, left - root->val); 

        tmp.pop_back(); 
    }
}; 

int main()
{

    return 0; 
}
