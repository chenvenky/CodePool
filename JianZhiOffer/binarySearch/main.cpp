#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (size == 0)
            return 0;
    int left = 0, right = size - 1;
    int mid = 0;
    while (rotateArray[left] >= rotateArray[right]) {
        if (right - left == 1)
        {
            mid = right;
            break;
        }
        mid = left + (right - left) / 2;
        if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            return MinOrder(rotateArray, left, right);
    }

    if (rotateArray[mid] >= rotateArray[left])
        left = mid;
    else
        right = mid;

    return rotateArray[mid];
    }
private:
    int MinOrder(vector<int> &num, int left, int right) {
        int result = num[left];
        for (int i = left + 1; i < right; ++i)
        {
            if (num[i] < result)
                result = num[i];
        }
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
