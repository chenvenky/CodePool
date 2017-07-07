#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 精妙解法
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while(cur1 != cur2)
        {
            cur1 = (cur1 == NULL ? pHead2 : cur1->next);
            cur2 = (cur2 == NULL ? pHead1 : cur2->next);
        }
        return cur1;
    }
};

// 普通解法
/*
    先令长链表走List-len1 和 List-len2 的差
    然后，两个链表长度相同，一块向后走.
*/
class Solution2 {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        int len1 = ListLen(cur1);
        int len2 = ListLen(cur2);
        if (len1 > len2)
        {
            cur1 = Step(cur1, len1 - len2);
        }
        else if(len2 > len1)
        {
            cur2 = Step(cur2, len2 - len1);
        }
        while(cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
private:
    int ListLen(ListNode* pos)
    {
        if(pos == NULL)
            return 0;
        int count = 0;
        while(pos)
        {
            pos=pos->next;
            count++;
        }
        return count;
    }
    ListNode* Step(ListNode* pos, int n)
    {
        while(n--)
            pos = pos->next;
        return pos;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


