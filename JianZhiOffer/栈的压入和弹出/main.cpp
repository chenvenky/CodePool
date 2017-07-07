#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int>popV){
        if (pushV.size()==0) return false;
        vector<int> st;
        for (int i = 0, j = 0; i < pushV.size();)
        {
            st.push_back(pushV[i++]);
            while(j < popV.size() && popV[j] == st.back())
            {
                st.pop_back();
                j++;
            }
        }
        return st.empty();
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
