#include <iostream>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int leftDepth = getDepth(pRoot->left);
        int rightDepth = getDepth(pRoot->right);
        int diff = leftDepth - rightDepth;
        if (1 < diff || diff < -1)
            return false;
        else
            return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
    }
private:
    int getDepth(TreeNode* pur)
    {
        if (pur == NULL)
            return 0;
        int leftDepth = getDepth(pur->left);
        int rightDepth = getDepth(pur->right);
        return max(leftDepth, rightDepth)+1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
