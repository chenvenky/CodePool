#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	queue<TreeNode*> qq;
        if(!pRoot)
            return 0;
        qq.push(pRoot);
        int level = 0;
        while(!qq.empty())
        {
            level++;
            int len = qq.size();
            while(len--)
            {
                TreeNode* cur = qq.front();
                qq.pop();
                if(cur->left)
                    qq.push(cur->left);
                if(cur->right)
                    qq.push(cur->right);
            }
        }
        return level;
    }
};

class Solution2 {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	return (pRoot == NULL) ? 0 : max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
