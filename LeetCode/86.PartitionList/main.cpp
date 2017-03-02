#include <iostream>
using namespace std;

class Solution {
public:
    listNode* partition(ListNode* head, int x){
        ListNode left(0),  right(0);
        ListNode *l = &left, *r = &right;

        while(head){
            // 注意指针引用的特性
            ListNode* &ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;

            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
