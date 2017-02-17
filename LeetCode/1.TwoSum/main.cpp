#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**<
unordered_map 的运行效率最高，而 map 的运行效率较低。但是 map 提供了稳定效率并且是有序序列。
    map 占用的内存比 unordered_map 低， 而且 unordered_map 占用的内存是线性比例增长的。
    所以：需要无序容器，快速查找删除，不担心略高的内存时用 unordered_map； 有序容器稳定查找删除
    效率，内存很受限时用 map. */
vector<int> twoSum(vector<int> &numbers, int target)
{
    // 这道题目的关键在于： 建立 vector的值与其下标的映射。
    unordered_map<int, int> hash;
    vector<int> result;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        int numberToFind = target - numbers[i];

        // 如果找到目标值，返回它们的下标
        if (hash.find(numberToFind) != hash.end())
        {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        // 没有找到相应的数字，把它添加进 hash
        hash[numbers[i]] = i;
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
