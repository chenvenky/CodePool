#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> dict(256, -1);
    int ansLen = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i]] > start) // 有重复
            start = dict[s[i]]; // 重置起点到重复位置
        dict[s[i]] = i;
        ansLen = max(ansLen, i - start);    // 维护 最长连续子串的长度
    }
    return ansLen;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
