/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Tue 18 Jul 2017 06:56:05 AM PDT
*
* Description: 
    旋转数组的最小数字： 二分查找变形。     
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
        int minNumberInRotateArray(vector<int> rotateArray)
        {
            if(rotateArray.size() == 0)
                return 0; 

            int left = 0, right = rotateArray.size() - 1; 
            int mid = 0; 

            while(left < right)
            {
                if(right - left == 1)
                {
                    mid = right; 
                    break; 
                }
                
                mid = left + (right - left) / 2; 
                if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
                {
                    return findMin(rotateArray, left, right); 
                }

                if(rotateArray[mid] >= rotateArray[left])
                    left = mid; 
                else
                    right = mid; 
            }

            return rotateArray[mid]; 
        }

private:
    int findMin(vector<int> &arr, int left, int right)
    {
        for(int i = left + 1; i <= right; i++)
        {
            if(arr[i] < arr[i-1])
                return arr[i]; 
        }

        return arr[left]; 
    }
}; 

int main()
{

    return 0; 
}
