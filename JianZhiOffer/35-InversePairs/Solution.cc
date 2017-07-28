/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 28 Jul 2017 07:23:24 AM PDT
*
* Description: 
    数组中的逆序数。    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        int cnt = 0; 
        vector<int> T(data.size(), 0); 
        mergeSort(data, T, 0, data.size(), cnt); 

        return cnt; 
    }

private:
    void mergeSort(vector<int>&data, vector<int>&T, int begin, int end, int &cnt)
    {
        if(end - begin > 1)
        {
            int mid = begin + (end - begin) / 2; 
            int pos1 = begin, pos2 = mid, pos = begin; 
            mergeSort(data, T, begin, mid, cnt); 
            mergeSort(data, T, mid, end, cnt); 
            while(pos1 < mid || pos2 < end)
            {
                if(pos2 >= end ||(pos1 < mid && data[pos1] <= data[pos2]))
                    T[pos++] = data[pos1++]; 
                else
                {
                    T[pos++] = data[pos2++]; 
                    cnt += mid - pos1; 
                    cnt %= 1000000007;
                } 
            }
            for(pos = begin; pos < end; pos++)
                data[pos] = T[pos]; 
        }
    }
}; 

int main()
{

    return 0; 
}
