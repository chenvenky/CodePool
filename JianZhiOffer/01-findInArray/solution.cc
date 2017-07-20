/*************************************************************************
* File Name: solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Mon 17 Jul 2017 05:55:55 AM PDT
*
* Description: 
    二维数组中的查找：从有序的二维数组中查找数字。     
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

class Solution{
public:
    bool Find(int target, vector<vector<int> > array)
    {
        int row = array.size(); 
        if(row == 0)
            return false; 
        int col = array[0].size(); 
        int i = row - 1; 
        int j = 0; 

        while(i >= 0 && j < col)
        {
            if(target == array[i][j])
                return true; 
            else if(target > array[i][j])
                j++; 
            else 
                i--; 
        }

        return false; 
    }
};

int main()
{

    return 0; 
}
