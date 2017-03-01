#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
                if(sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
