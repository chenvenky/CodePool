#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<pair<int, int> > s;
public:
    void push(int value) {
        if(s.empty())
        {
            s.push(pair<int, int>(value, value));
        }
        else
        {
            s.push(pair<int, int>(value, std::min(value, s.top().second)));
        }
    }
    void pop()
    {
        s.pop();
    }
    int top()
    {
        return s.top().first;
    }
    int min()
    {
        return s.top().second;
    }
};
int main()
{

    return 0;
}
