#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==NULL)
            return NULL;
        ListNode* pre = NULL, *next = NULL;
        while(pHead != NULL)
        {
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
