#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int preLen = pre.size();
        int vinLen = vin.size();
        if(preLen == 0 || vinLen == 0 || preLen != vinLen)
            return NULL;
        int mid = find(vin.begin(), vin.end(), pre[0]) - vin.begin();
        if(mid == preLen)
            throw std::runtime_error("Invalid input");
        vector<int> left_pre(pre.begin()+1, pre.begin()+mid+1);
        vector<int> right_pre(pre.begin()+mid+1, pre.end());
        vector<int> left_in(vin.begin(), vin.begin()+mid);
        vector<int> right_in(vin.begin()+mid+1, vin.end());
        if(left_pre.size() != left_in.size() || right_pre.size() != right_in.size())
            throw std::runtime_error("Invalid input");
        TreeNode* root = new TreeNode(pre[0]);
        root->left = reConstructBinaryTree(left_pre, left_in);
        root->right = reConstructBinaryTree(right_pre, right_in);
        return root;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
