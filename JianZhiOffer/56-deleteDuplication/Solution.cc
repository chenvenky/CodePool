/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 04:13:22 AM PDT
*
* Description: 
    删除链表中重复的节点：　递归删除。   
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
    ListNode *next; 
    ListNode(int x) : 
        val(x), next(NULL)
        {

        }
}; 

class Solution
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL; 
        if(pHead->next == NULL)
            return pHead; 

        if(pHead->val == pHead->next->val)
        {
            ListNode* pos = pHead->next; 
            while(pos != NULL && pHead->val == pos->val)
            {
                ListNode* tmp = pos->next; 
                delete pos; 
                pos = tmp; 
            }
            return deleteDuplication(pos); 
        }
        else
        {
            ListNode* pos = deleteDuplication(pHead->next); 
            pHead->next = pos; 
            return pHead; 
        }
    }
}; 

int main()
{

    return 0; 
}
