#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);
    vector<double> medians;
    for (int i=k; ; i++) {

        // Push the current median.
        medians.push_back((double(*mid) + *next(mid, k%2 - 1)) / 2);

        // If all done, return.
        if (i == nums.size())
            return medians;

        // Insert nums[i].
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;

        // Erase nums[i-k].
        if (nums[i-k] <= *mid)
            mid++;
        window.erase(window.lower_bound(nums[i-k]));
    }
}

int main()
{
    vector<int>nums{1, 3, -1, -3, 5, 3, 6, 7};
    vector<double> ans = medianSlidingWindow(nums, 3);
    for(auto i: ans)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
