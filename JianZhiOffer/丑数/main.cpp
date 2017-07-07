#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_solution(int index)
    {
        if (index < 7)
            return index;
        vector<int> res(index);
        res[0] = 1;
        // t2 个质因子 2， t3 个质因子3， t5 个质因子 5
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2) t2++;
            if (res[i] == res[t3] * 3) t3++;
            if (res[i] == res[t5] * 5) t5++;
        }
        return res[index - 1];  // 因为没有算 1 是丑数
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
