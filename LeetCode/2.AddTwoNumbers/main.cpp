#include <iostream>
using namespace std;

// Definition for single-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution{
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int extra = 0;
        ListNode preHead(0), *p = &preHead;
        int sum = 0;
        while(l1 || l2 || extra)
        {
            if (l1)
                sum = l1->val;
            else
                sum = 0;
            if (l2)
                sum += l2->val;
            sum += extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};

int main()
{
    ListNode l1(2), *p1 = &l1;
    p1->next = new ListNode(4);
    p1 = p1->next;
    p1->next = new ListNode(3);
    p1 = p1->next;

    ListNode l2(5), *p2 = &l2;
    p2->next = new ListNode(6);
    p2 = p2->next;
    p2->next = new ListNode(4);
    p2 = p2->next;
    Solution JJ;
    ListNode *ans = JJ.addTwoNumbers(&l1, &l2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
