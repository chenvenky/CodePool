/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Sat 22 Jul 2017 02:47:47 AM PDT
*
* Description: 
    机器人的运动范围。     
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
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold <= 0 || rows <= 0 || cols <= 0)
            return 0; 

        bool* pic = new bool[rows * cols]();    // () is important
        int res = dfs(threshold, rows, cols, 0, 0, pic); 
        delete[] pic; 

        return res; 
    }
private:
    int dfs(int k, int rows, int cols, int i, int j, bool* pic)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return 0; 
        if(pic[i * cols + j] || !checkIn(i, j, k))
            return 0; 

        pic[i * cols + j] = true; 
        return  (dfs(k, rows, cols, i + 1, j, pic) +
                 dfs(k, rows, cols, i - 1, j, pic) + 
                 dfs(k, rows, cols, i, j - 1, pic) + 
                 dfs(k, rows, cols, i, j + 1, pic) + 1
                ); 
    }

    bool checkIn(int i, int j, int k)
    {
        int sum = 0; 
        while(i || j)
        {
            sum += i % 10; 
            sum += j % 10; 
            i /= 10; 
            j /= 10;
        }

        return (sum <= k); 
    }
}; 

int main()
{
    return 0; 
}
