#include <iostream>
/**
* Definition for a binary tree node.
* struct TreeNode {
*   int val;
*   TreeNode *left;
*   TreeNode *right;
*   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*};
*/

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode *q){
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);    // 左子树中寻找 LCA
        TreeNode* right = lowestCommonAncestor(root->right, p, q);  // 右子树中寻找 LCA
        if (left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
    }
};
/**<
root = 3
p = 5
q = 1

left = f(5, 5, 1) --> 5
right = f(1, 5, 1) --> 1

 */
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
