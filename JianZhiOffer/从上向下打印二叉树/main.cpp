#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        TreeNode* pos = root;
        qu.push(pos);
        while(!qu.empty())
        {
            pos = qu.front();
            qu.pop();
            if (!pos)
                continue;
            ans.push_back(pos->val);
            qu.push(pos->left);
            qu.push(pos->right);
        }
        return ans;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
