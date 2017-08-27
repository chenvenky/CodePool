/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Fri 25 Aug 2017 09:36:35 PM PDT
*
* Description: 
    序列化二叉树：　先序遍历    
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
#include <cstring>
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
    char* Serialize(TreeNode* root)
    {
        if(root == NULL)
            return "#"; 

        string r = to_string(root->val); 
        r += ','; 
        char* left = Serialize(root->left); 
        char* right = Serialize(root->right); 
        char* ret = new char[r.size() + strlen(left) + strlen(right)]; 

        strcpy(ret, r.c_str()); 
        strcat(ret, left); 
        strcat(ret, right); 

        return ret; 
    }

    TreeNode* Deserialize(char *str)
    {
        if(str == NULL)
            return NULL; 

        return decode(str); 
    }

private:
    TreeNode* decode(char* &str)
    {
        if(*str == '#')
        {
            str++; 
            return NULL; 
        }
        int num = 0; 
        while(*str != ',')
            num = num*10 + (*(str++) - '0'); 
        str++; 

        TreeNode* root = new TreeNode(num); 
        root->left = decode(str); 
        root->right = decode(str); 

        return root; 
    }
}; 

int main()
{

    return 0; 
}
