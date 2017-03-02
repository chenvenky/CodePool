#include <iostream>
using namespace std;

// 常规算法
class Solution{
public:
    int hammingDistance(int x, int y){
        int count = 0;
        while (x!=0 || y!=0)
        {
            if (x%2 != y%2)
                count++;
            x /= 2;
            y /= 2;
        }
        return count;
    }
};

// 位运算
class Solution{
public:
    int hammingDistance(int x, int y){
    int dist = 0;
    int n = x ^ y;
    while (n){
        ++dist;
        n &= n - 1;
    }
    }
};

int main()
{
    int ans = 4 ^ 1;
    cout << ans << endl;
    return 0;
}
