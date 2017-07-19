/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 05:40:03 AM PDT
*
* Description: 
    链表中倒数第 k 个结点。     
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
    ListNode(int x) : val(x), next(NULL) {

    }
}; 

class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == NULL || k == 0)
            return NULL; 
        if(k < 0)
            throw runtime_error("Invalid Parameter"); 

        ListNode* pos1 = pListHead; 
        ListNode* pos2 = pListHead; 
        while(k != 0 && pos1 != NULL)
        {
            pos1 = pos1->next;
            k--; 
        }

        if(k > 0)
            return NULL; 

        while(pos1 != NULL)
        {
            pos1 = pos1->next; 
            pos2 = pos2->next; 
        }

        return pos2; 
    }

}; 

int main()
{

    return 0; 
}
