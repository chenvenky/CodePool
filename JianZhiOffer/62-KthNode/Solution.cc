/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Tue 22 Aug 2017 07:45:39 AM PDT
*
* Description: 
    二叉搜索树的第 k 个结点。　    
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
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
}; 

class Solution
{
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* pos = pRoot; 
        stack<TreeNode*> st; 
        int cnt = 0; 

        while(!st.empty() || pos != NULL)
        {
            if(pos != NULL)
            {
                st.push(pos); 
                pos = pos->left; 
            }
            else
            {
                pos = st.top(); 
                st.pop(); 
                cnt++; 
                if(cnt == k)
                    return pos; 
                pos = pos->right; 
            }
        }

        return NULL; 
    }
}; 

int main()
{

    return 0; 
}
