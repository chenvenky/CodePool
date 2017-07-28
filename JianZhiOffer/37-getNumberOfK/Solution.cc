/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 28 Jul 2017 07:59:58 AM PDT
*
* Description: 
    数字在排序数组中出现的次数。 二分查找    
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

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
            return 0; 
        
        int upper = getUpper(data, k);
        int lower = getLower(data, k); 
        if(data[lower] != k)
            return 0; 
        else 
            return (upper - lower); 
    }
    
private:
    int getUpper(vector<int> &data, int val)
    {
        int begin = 0, end = data.size(); 
        int mid; 
        while(end > begin)
        {
            mid = begin + (end - begin) / 2;
            if(val >= data[mid])
                begin = mid + 1; 
            else
                end = mid; 
        }
        
        return begin; 
    }
    
    int getLower(vector<int> &data, int val)
    {
        int begin = 0, end = data.size(); 
        int mid; 
        while(end > begin)
        {
            mid = begin + (end - begin) / 2; 
            if(val <= data[mid])
                end = mid; 
            else 
                begin = mid + 1; 
        }
        
        return begin; 
    }
};

int main()
{
	return 0; 
}

