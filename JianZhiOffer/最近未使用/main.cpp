// 最近未使用的内存分配方式
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int QSize = 3;    // 计算机拥有的存储器分区数

struct event
{
    int val;
    int id;
    event(int x, int y):val(x), id(y) { }
};

bool operator<(const event &a, const event &b)
{
    return a.id > b.id;
}


int main()
{
    vector<int> work;
    int m;
    cout << "输入作业到达顺序：\n";
    while(cin >> m)
    {
        work.push_back(m);
    }
    stack <event> temp;
    int flag[100];
    memset(flag, 0, sizeof(flag));
    priority_queue<event> qq;
    int losePage = 0;
    for(int i = 0; i < work.size(); i++)
    {
        if(qq.size() < QSize && flag[work[i]]==0)
        {
            qq.push(event(work[i],i));
            flag[work[i]]=1;
        }
        if(flag[work[i]]==0)
        {
            cout << "出现缺页，把页面：" << qq.top().val << "换出" << endl;
            losePage++;
            flag[qq.top().val] = 0;
            qq.pop();
            qq.push(event(work[i],i));
            flag[work[i]] = 1;
        }
        if(flag[work[i]]==1)
        {
            // 更新
            while(qq.top().val != work[i])
            {
                temp.push(qq.top());
                qq.pop();
            }
            qq.pop();
            qq.push(event(work[i],i));
            while(!temp.empty())
            {
                qq.push(temp.top());
                temp.pop();
            }
        }
    }
    cout << "缺页率为：" << losePage << "/" << work.size() << endl;
    return 0;
}
