#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return Judge(sequence, 0, sequence.size() - 1);
    }

private:
    bool Judge(vector<int>&seq, int left, int right)
    {
        if (left >= right)
            return true;
        int pos = right;
        while(pos > left && seq[pos-1] > seq[right])
            pos--;
        for(int i = pos - 1; i >= left; i--)
            if (seq[i] > seq[right])
                return false;
        return (Judge(seq, left, pos-1) && Judge(seq, pos, right-1));
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
