#include <iostream>
using namespace std;

int solve(int n)
{
    int ans = 0;
    unsigned int nn;
    nn = (unsigned)n;

    cout << nn << endl;
    while (nn)
    {
        nn = nn & (nn-1);
        ans++;
    }
    return ans;
}

int main()
{
    cout << solve(-2) << endl;
    return 0;
}
