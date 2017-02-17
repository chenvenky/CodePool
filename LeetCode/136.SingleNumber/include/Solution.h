#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

class Solution
{
    public:
        int singleNumber(vector<int>& nums){
        int ans = 0;
        for (auto i : nums)
            ans ^= i;
        return ans;
        }
};

#endif // SOLUTION_H
