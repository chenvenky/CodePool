#include <iostream>
using namespace std;

// 递归版
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;
        // 1. 将左子树构造成双链表，并返回链表头节点
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* pos = left;
        // 2. 定位至左子树双链表最后一个节点
        while(pos!=NULL && pos->right != NULL)
            pos = pos->right;
        // 3. 如果左子树链表不为空的话，将当前 root 追加到左子树链表
        if(left != NULL)
        {
            pos->right = pRootOfTree;
            pRootOfTree->left = pos;
        }
        // 4. 将右子树构造成双链表， 并返回链表头节点
        TreeNode* right = Convert(pRootOfTree->right);

        // 5. 如果右子树不为空的话， 将该链表追加到 root 节点之后
        if (right != NULL)
        {
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }

        return left!=NULL ? left : pRootOfTree;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
