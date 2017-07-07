#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// (start + end) * (end - start + 1) = 2 * S
// (start + end) * (end - start + 1) = a * b (a < b)
// start = (b - a + 1) / 2
// end = (a + b - 1) / 2
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        vector<int> temp;
        if (sum < 3)
            return ret;
        int S = sum * 2;
        for(int a = 2; a <= (int)sqrt(S); a++)
        {
            if (S % a == 0)
            {
                int b = S / a;
                if (!((b - a + 1) & 1) && !((a + b - 1) & 1))
                {
                    int start = (b - a + 1) / 2;
                    int end = (a + b - 1) / 2;
                    for(int i = start; i <= end; i++)
                        temp.push_back(i);
                    ret.insert(ret.begin(), temp);
                    temp.clear();
                }
            }
        }
        return ret;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
