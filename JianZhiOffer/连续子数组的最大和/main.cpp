#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.size()==0)
            return 0;
        int tot = array[0];
        int sumMax = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            if (tot > 0)
                tot += array[i];
            else
                tot = array[i];

            sumMax = max(tot, sumMax);
        }
        return sumMax;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
