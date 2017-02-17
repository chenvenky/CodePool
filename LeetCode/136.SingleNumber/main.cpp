#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 3, 1};
    Solution ss;
    cout << ss.singleNumber(vec) << endl;
    return 0;
}
