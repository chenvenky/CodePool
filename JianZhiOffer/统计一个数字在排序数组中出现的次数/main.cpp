#include <iostream>
#include <vector>
using namespace std;

// 二分查找：获得最小下标
int getLower(vector<int> &data, int k)
{
    int start = 0, end = data.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if(data[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
        mid = (start + end) / 2;
    }

    return start;
}

int getUpper(vector<int>& data, int k)
{
    int start = 0, end = data.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (data[mid] <= k)
            start = mid + 1;
        else
            end = mid - 1;
        mid = (start + end) / 2;

        return end;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
