/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 04:47:34 AM PDT
*
* Description: 
    链表中环的入口节点：　一快，一慢。    
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
    ListNode* next; 
    ListNode(int x) : val(x), next(NULL)
    {

    }
}; 

class Solution
{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return NULL; 

        ListNode* fastPos = pHead; 
        ListNode* slowPos = pHead; 
        while(slowPos != NULL && fastPos != NULL)
        {
            slowPos = slowPos->next; 
            fastPos = fastPos->next; 
            if(fastPos == NULL)
                break; 
            fastPos = fastPos->next; 

            if(slowPos == fastPos)
                break;
        }
        
        if(slowPos == NULL || fastPos == NULL)
            return NULL; 
        fastPos = pHead; 
        while(fastPos != slowPos)
        {
            fastPos = fastPos->next; 
            slowPos = slowPos->next; 
        }

        return slowPos; 
    }
}; 

int main()
{

    return 0; 
}
