/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 07:07:47 AM PDT
*
* Description: 
    合并两个排序的链表    
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
    ListNode(int x) : 
        val(x), next(NULL)
        {

        }
}; 

class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2; 
        if(pHead2 == NULL)
            return pHead1; 

        if(pHead1->val <= pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2); 
            return pHead1; 
        }
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next); 
            return pHead2; 
        }
    }
}; 


int main()
{

    return 0; 
}
