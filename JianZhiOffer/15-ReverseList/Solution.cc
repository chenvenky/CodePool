/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 06:54:43 AM PDT
*
* Description: 
    反转链表。     
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

struct ListNode
{
    int val; 
    struct ListNode *next; 
    ListNode(int x) : val(x), next(NULL)
    {

    }
};

class Solution
{
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return pHead; 

        ListNode* pre = pHead; 
        ListNode* pos = pHead->next; 
        pHead->next = NULL; 
        
        while(pos->next != NULL)
        {
            ListNode* next = pos->next; 
            pos->next = pre; 
            pre = pos; 
            pos = next; 
        }
        pos->next = pre; 
        
        return pos; 
    }
}; 

int main()
{

    return 0; 
}
