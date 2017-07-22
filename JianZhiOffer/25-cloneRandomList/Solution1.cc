/*************************************************************************
* File Name: Solution1.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 21 Jul 2017 05:58:46 AM PDT
*
* Description: 
    复杂链表的复制： unordered_map    
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

struct RandomListNode
{
    int label;
    RandomListNode *next, *random; 
    RandomListNode(int x) : 
        label(x), next(NULL), random(NULL)
        {

        }
}; 

class Solution
{
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL; 
        unordered_map<RandomListNode*, RandomListNode*> mm; 
        RandomListNode* pos1 = pHead; 
        RandomListNode* ans = new RandomListNode(pHead->label); 
        RandomListNode* pos2 = ans; 

        while(pos1->next != NULL)
        {
            mm[pos1] = pos2; 
            pos2->next = new RandomListNode(pos1->next->label); 
            pos1 = pos1->next; 
            pos2 = pos2->next; 
        }
        pos2->next = NULL; 
        mm[pos1] = pos2; 

        pos1 = pHead; 
        pos2 = ans; 
        while(pos1)
        {
            pos2->random = mm[pos1->random]; 
            pos1 = pos1->next; 
            pos2 = pos2->next; 
        }

        return ans; 
    }
}; 


int main()
{

    return 0; 
}
