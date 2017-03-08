#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){
        vector<int> ans;
        int i = 0;
        while(i < nums.size()){
            if (nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for (i = 0; i < nums.size(); i++)
            if (nums[i] != i+1) ans.push_back(nums[i]);
        return ans;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
/*
2 1 2

nums[0] != nums[1]
1 2 2 3

nums[1] = nums[1]
nums[2] = nums[1]
nums [3] = nums[]

1 2 3 2
num[0] == nums[0]
i


 nums[0] != nums[3]
 nums[3] = 4
 nums[0] = 7
 nums[0] != nums[6]


*/
