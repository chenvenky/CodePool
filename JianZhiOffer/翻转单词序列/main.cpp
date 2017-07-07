#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string ret = "";
        string temp = "";
       	for(size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                ret = ' ' + temp + ret;
                temp = "";
            }
            else
                temp += str[i];
        }
        if (temp.size())
            ret = temp + ret;
        return ret;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
