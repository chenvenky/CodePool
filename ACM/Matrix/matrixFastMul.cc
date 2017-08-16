/*************************************************************************
* File Name: matrixFastMul.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Sat 05 Aug 2017 09:33:53 PM PDT
*
* Description: 
    矩阵快速幂。     
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
#include <cstring>
using namespace std;

vector<vector<int>> mul(vector<vector<int>> &lhs, vector<vector<int>> &rhs)
{
    //TODO: 判断矩阵相乘是否合法
    vector<vector<int>> tmp(lhs.size(), vector<int>(rhs[0].size(), 0));
    const int row = lhs.size(); 
    const int col = lhs[0].size(); 
    for(int i = 0; i < row; i++)
    {
        for(int k = 0; k < col; k++)
        {
            if(lhs[i][k])
                for(int j = 0; j < col; j++)
                    tmp[i][j] = (tmp[i][j] + lhs[i][k] * rhs[k][j]); 
        }
    } 

    return tmp; 
}

vector<vector<int>> fastMul(vector<vector<int>> &base, int n)
{
    //TODO: 判断矩阵是否是 n * n
    const int Len = base.size(); 
    vector<vector<int>> ans(Len, vector<int>(Len, 0)); 
    for(int i = 0; i < Len; i++)        // 初始化单位矩阵
        ans[i][i] = 1; 

    while(n)
    {
        if(n & 1)
            ans = mul(ans, base); 
        base = mul(base, base);
        n >>= 1;  
    }

    return ans; 
}

int main()
{
    vector<vector<int>> fibMatrix{ {1, 1}, {1, 0} }; 
    vector<vector<int>> fib{{1, 1}}; 

    fibMatrix = fastMul(fibMatrix, 3); 
    fib = mul(fib, fibMatrix); 

    for(auto it : fib)
    {
        for(auto item : it)
            cout << item << "\t"; 
        cout << endl; 
    }

    return 0; 
}
