#include <iostream>
#include <vector>
using namespace std;

// Hash
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		unordered_map<int, int> hh;
        for(int i = 0; i < data.size(); i++)
            hh[data[i]]++;
        vector<int> ans;
        for(int i = 0; i < data.size(); i++)
            if (hh[data[i]] == 1)
                ans.push_back(data[i]);
        *num1 = ans[0];
        *num2 = ans[1];
    }
};

// Î»ÔËËã
class Solution2 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int flag = 1;
        int tmp = 0;
        for(int i = 0; i < data.size(); i++)
            tmp ^= data[i];
        while((tmp & flag) == 0)
            flag <<= 1;

        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if ((flag & data[i]) == 0)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
