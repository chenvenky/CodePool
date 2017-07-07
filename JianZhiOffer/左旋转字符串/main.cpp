#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n){
        int len = str.length();
        if (len == 0)
            return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

class Solution2 {
public:
    string LeftRotateString(string str, int n)
    {
        reverse(str.begin(), str.begin()+n);
        reverse(str.begin()+n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};

class Solution3 {
public:
    void rev(string &s, int start, int end)
    {
        while (start < end)
        {
            char temp;
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    string LeftRotateString(string str, int n){
        int len = str.length();
        if (0 == len || 0 == n)
            return str;
        string &temp = str;
        rev(temp, 0, n - 1);
        rev(temp, n, len - 1);
        rev(temp, 0, len - 1);
        return str;
    }
};
