// URL: http://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html
#include <iostream>
using namespace std;

// 计算数字 X 在 1 - n 中出现的次数（0除外）
int count(int n, int x);

// 计算数字 0 在 1 - n 中出现的次数
int count0(int n);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int count(int n, int x)
{
    int cnt = 0, k;
    // i 表示计算 第 i 位（左）
    for (int i = 1; k = n / i; i *= 10)
    {
        // k / 10 为高位数字
        cnt += (k / 10) * i;
        // 当前位的数字
        int cur = k % 10;
        if (cur > x)
            cnt += i;
        else if(cur == x)
        {
            // n - k * i 为低位的数字
            cnt += n - k * i + 1;
        }
    }
    return cnt;
}

