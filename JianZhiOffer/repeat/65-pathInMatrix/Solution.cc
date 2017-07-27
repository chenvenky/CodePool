/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Sat 22 Jul 2017 02:05:07 AM PDT
*
* Description: 
    矩形中的路径: DFS    
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
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	if(matrix == NULL || rows <= 0 || cols <= 0 || str == NULL)
            return false; 
        
        bool *pic = new bool[rows * cols]();    // 注意最后的括号，初始化
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(dfs(matrix, rows, cols, str, i, j, pic))
                {
                    delete[] pic;
                    return true;  
                }

        delete[] pic; 
        return false; 
    }
    
private:
    bool dfs(char* matrix, int rows, int cols, char* str, int i, int j, bool* pic)
    {
        if(*str == '\0')
            return true; 
            
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false; 
        if(pic[i * cols + j] || *str != matrix[i * cols + j])
            return false; 
        
        pic[i * cols + j] = true; 
        bool sign = dfs(matrix, rows, cols, str + 1, i + 1, j, pic) ||
            		dfs(matrix, rows, cols, str + 1, i - 1, j, pic) ||
            		dfs(matrix, rows, cols, str + 1, i, j - 1, pic) ||
            		dfs(matrix, rows, cols, str + 1, i, j + 1, pic); 
        
        pic[i * cols + j] = false; 
        return sign; 
    }

};

int main()
{

    return 0; 
}
