#include <iostream>
#include <map>
using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) { }
};

// 先复制再分离
/*
    1. 复制每个节点， 如：复制节点 A 得到 A1, 将A1插入节点 A 后面
    2. 遍历链表，A1->random = A->random->next (因为每个原节点后都是它的复制)
    3. 将链表拆分成原链表和复制后的链表
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode* currNode = pHead;
        // 步骤 1
        while(currNode)
        {
            RandomListNode* node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }

        // 步骤 2
        currNode = pHead;
        while(currNode)
        {
            RandomListNode* node = currNode->next;
            if (currNode->random)
            {
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }

        // 步骤 3
        RandomListNode* pCloneHead = pHead->next;
        RandomListNode* tmp;
        currNode = pHead;
        // currNode 轮换的指向原节点，复制节点，并每隔一个节点相连
        while(currNode->next)
        {
            tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }

        return pCloneHead;
    }
};

// 递归
/*
    此题转化为一个头节点和除去头节点剩余部分， 剩余部分操作和原问题一致
*/
class Solution2 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;

        // 开辟一个新节点
        RandomListNode* pCloneHead = new RandomListNode(pHead->label);
        pCloneHead->next = pHead->next;
        pCloneHead->random = pHead->random;

        // 递归其他节点
        pCloneHead->next = Clone(pHead->next);
        return pCloneHead;
    }
};

// Hash法 || map
class Solution3 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        map<RandomListNode*, RandomListNode*> mm;
        RandomListNode* pos1 = pHead;
        RandomListNode* pAns = new RandomListNode(pHead->label);
        RandomListNode* pos2 = pAns;
        mm[pos1] = pos2;
        while(pos1)
        {
           	if (pos1->next)
                pos2->next = new RandomListNode(pos1->next->label);
            else
                pos2->next = NULL;
            pos1 = pos1->next;
            pos2 = pos2->next;
            mm[pos1] = pos2;
        }

        pos1 = pHead;
        pos2 = pAns;
        while(pos1)
        {
            pos2->random = mm[pos1->random];
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        return pAns;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
