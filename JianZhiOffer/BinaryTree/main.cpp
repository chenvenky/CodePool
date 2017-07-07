#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

// 先序遍历
void preOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// 后序遍历
void lastOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    lastOrder(root->left);
    lastOrder(root->right);
    cout << root->val << " ";
}

// 非递归写法
// 先序遍历： 入栈顺序  右子树 -> 左子树 -> 根
//            出栈顺序  根 -> 左子树 -> 右子树
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> temp;
        if(root == NULL)
            return res;
        temp.push(root);
        while(!temp.empty())
        {
            TreeNode* pos = temp.top();
            temp.pop();
            res.push_back(pos->val);
            if(pos->right != NULL)
                temp.push(pos->right);
            if(pos->left != NULL)
                temp.push(pos->left);
        }
        return res;
}

// 中序遍历
// 入栈顺序： 右子树 -> 根 -> 左子树
// 只有当左子树已经访问完后，才能访问根节点
/*
    对于任一节点 P
    1)  若其左孩子不为空，则将 P 入栈并将 P 的左孩子置为当前 P ,
        然后对当前 P 再进行相同的处理；
    2)  若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶节点，
        然后将当前 P 置为栈顶节点的右孩子；
    3)  直到 P 为 NULL 并且栈为空则遍历结束；
*/
vector<int> inOrderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> temp;
    if(root == NULL)
        return res;
    TreeNode* pos = root;
    while(!temp.empty() || pos != NULL)
    {
        if(pos != NULL){
            // push 左子树入栈
            temp.push(pos);
            pos = pos->left;
        }
        else
        {
            pos = temp.top();
            temp.pop();
            res.push_back(pos->val);
            pos = pos->right;
        }
    }
    return res;
}

// 后序遍历
// 先入栈根，然后是右子树，最后左子树
// 要求最后访问根节点， 即访问该根节点时必须访问完左子树和右子树，
// 我们只需要保证访问某一节点时，该节点的右子树已经被访问， 否则需要
// 将该节点重新压入栈。
/*
对于任一结点 P, 将其入栈， 然后沿其左子树一直往下搜索， 直到搜索到没有左孩子的结点，
此时该结点出现在栈顶，但是此时不能将其出栈并访问，因为其右孩子还没有被访问。
所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在
栈顶，此时可以将其出栈并访问。 这样就保证了正确的访问顺序。 可以看出，在这个过程中，
每个结点都两次出现在栈顶，并且只有第二次出现在栈顶时，才能访问它。
*/
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tmp;
        if(root == NULL)
            return res;
        TreeNode* pos = root;   // 记录正在访问的结点
        TreeNode* pre = NULL;   // 记录前一个访问的结点
        do
        {
            while(pos != NULL)      // 把左子树结点都压进栈
            {
                tmp.push(pos);
                pos = pos->left;
            }
            pre = NULL;             // 左结点压完后，初始化前一个访问结点为 NULL
            while(!tmp.empty())
            {
                pos = tmp.top();
                tmp.pop();
                if(pos->right == pre)       // 右孩子已经被访问
                {
                    res.push_back(pos->val);    // 右孩子已经被访问，可以访问该结点
                    pre = pos;      // 记录刚刚访问的结点
                }
                else
                {
                    tmp.push(pos);  // 第一次访问该结点，再次放入栈中
                    pos = pos->right;
                    break;
                }
            }
        } while(!tmp.empty());

        return res;
    }
int main()
{
    return 0;
}
