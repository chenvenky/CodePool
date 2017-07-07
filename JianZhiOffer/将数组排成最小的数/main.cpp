#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/*
对 vector 容器内的数据进行排序， 按照 将 a 和 b 转为 string 后
若 a + b < b + a  a 排在前的规则。
如 21 2 因为 212 < 221 所以 排序为 21 2
to_string() 可以将 int 转化为 string
*/
class Solution {
    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        A += a;
        A += b;
        B += b;
        B += a;

        return A < B;
    }
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string answer = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
            answer += numbers[i];

        return answer;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
