#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    void heapSort(vector<int> &input, int root, int end)
    {
        for (int j = end - 1; j >= root; j--)
        {
            int parent = (j + root -1)/2;
            if (input[parent] > input[j])
            {
                int temp = input[j];
                input[j] = input[parent];
                input[parent] = temp;
            }
        }
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        if (k > input.size()) return result;
        for (int i = 0; i < k; i++)
        {
            heapSort(input, i, input.size());
            result.push_back(input[i]);
        }
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
