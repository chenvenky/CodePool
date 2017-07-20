/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Thu 20 Jul 2017 05:09:14 AM PDT
*
* Description: 
    顺时针打印矩阵： 注意边界。    
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
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> res; 
        int row = matrix.size();    // 行数
        if(row == 0)
            return res; 
        int col = matrix[0].size(); // 列数
        int circle = ((row < col ? row : col) - 1) / 2 + 1;     // 圈数
        for(int i = 0; i < circle; i++)
        {
            // 从左向右打印一行
            for(int j = i; j < col - i; j++)
                res.push_back(matrix[i][j]);
            // 从上向下打印一列
            for(int k = i + 1; k < row - i; k++)
                res.push_back(matrix[k][col-1-i]); 
            // 从右向左打印一行
            for(int m = col - 2 - i; (m >= i) && (row - 1 - i != i); m--)
                res.push_back(matrix[row-1-i][m]); 
            // 从下向上打印一列
            for(int n = row - 2 - i; (n > i) && (col - 1 - i != i); n--)
                res.push_back(matrix[n][i]); 
        }

        return res; 

    }
}; 


int main()
{

    return 0; 
}
