/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 17 Jul 2017 06:49:26 AM PDT
*
* Description: 
    从头到尾打印链表： 递归。     
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
    struct ListNode* next; 
    ListNode(int x) : val(x), next(NULL) {

    }
}; 

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> res; 
        if(head != NULL)
        {
            if(head->next != NULL)
            {
                res = printListFromTailToHead(head->next); 
            }
            res.push_back(head->val); 
        }

        return res; 
    }
};

int main()
{

    return 0; 
}
