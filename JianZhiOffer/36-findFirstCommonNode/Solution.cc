/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 28 Jul 2017 07:41:58 AM PDT
*
* Description: 
    两个链表的第一个公共结点。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getLen(pHead1); 
        int len2 = getLen(pHead2); 
        
        if(len1 > len2)
        {
            int len = len1 - len2; 
            while(len--)
            {
                pHead1 = pHead1->next; 
            }
        }
        else
        {
            int len = len2 - len1; 
            while(len--)
            {
                pHead2 = pHead2->next; 
            }
        }
        
        while(pHead1 != pHead2)
        {
            pHead1 = pHead1->next; 
            pHead2 = pHead2->next; 
        }
        
        return pHead1; 
    }
    
private:
    int getLen(ListNode* head)
    {
        int len = 0; 
        while(head != NULL)
        {
            len++; 
            head = head->next; 
        }
        
        return len; 
    }
};


int main()
{
	
	return 0; 
}
