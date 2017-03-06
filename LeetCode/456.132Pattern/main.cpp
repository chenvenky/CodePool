#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int med = INT_MIN;
        stack<int> st;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (nums[i] < med) return true;
            else while(!st.empty() && nums[i] > st.top())
            {
                med = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> test = {3, 5, 0, 3, 4};
    Solution solve;
    cout << solve.find132pattern(test) << endl;
    return 0;
}
