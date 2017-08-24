/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 03:48:53 AM PDT
*
* Description: 
    二叉树的下一个节点: 二搜索叉树寻找下一个节点的方法   
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

struct TreeLinkNode
{
    int val; 
    TreeLinkNode* left; 
    TreeLinkNode* right; 
    TreeLinkNode* next; 
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {

    }
}; 
class Solution
{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL; 
        if(pNode->right != NULL)
        {
            TreeLinkNode* pos = pNode->right; 
            while(pos->left != NULL)
                pos = pos->left; 
            return pos; 
        }

        TreeLinkNode* fa = pNode->next; 
        while(fa != NULL)
        {
            if(pNode == fa->left)
                return fa; 
            else
            {
                pNode = fa; 
                fa = pNode->next; 
            }
        }

        return NULL; 
    }
}; 

int main()
{

    return 0; 
}
