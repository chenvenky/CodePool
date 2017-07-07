#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;
        ListNode* cur = NULL;
        if(pHead1->val < pHead2->val)
        {
            cur = pHead1;
            cur->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            cur = pHead2;
            cur->next = Merge(pHead1, pHead2->next);
        }

        return cur;
    }
};


class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;
        ListNode* cur = NULL, *ret = NULL;

        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val < pHead2->val)
            {
                if (ret == NULL)
                {
                    cur = ret = pHead1;
                }
                else
                {
                    cur->next = pHead1;
                    cur = cur->next;
                }
                pHead1 = pHead1->next;
            }
            else
            {
                if (result == NULL)
                {
                    cur = ret = pHead2;
                }
                else
                {
                    cur->next = pHead2;
                    cur = cur->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 == NULL)
            cur->next = pHead2;
        if (pHead2 == NULL)
            cur->next = pHead1;

        return ret;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
