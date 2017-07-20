/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 17 Jul 2017 07:37:37 AM PDT
*
* Description: 
    重建二叉树： 根据二叉树的前序遍历和中序遍历重建二叉树。     
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
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
}; 

class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if(pre.size() != vin.size())
            throw runtime_error("Invalid Parameters"); 

        if(pre.size() == 0)
            return NULL; 

        int mid = find(vin.begin(), vin.end(), pre[0]) - vin.begin(); 
        vector<int> lPre(pre.begin() + 1, pre.begin() + mid + 1); 
        vector<int> rPre(pre.begin() + mid + 1, pre.end()); 
        vector<int> lVin(vin.begin(), vin.begin() + mid); 
        vector<int> rVin(vin.begin() + mid + 1, vin.end()); 

        TreeNode *root = new TreeNode(pre[0]); 
        root->left = reConstructBinaryTree(lPre, lVin); 
        root->right = reConstructBinaryTree(rPre, rVin); 

        return root; 
    }
}; 

int main()
{

    return 0; 
}
