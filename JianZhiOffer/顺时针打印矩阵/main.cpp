#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        res.clear();
        int row = matrix.size();    // 行数
        int col = matrix[0].size(); // 列数
        // 计算打印的圈数
        int circle = ((row < col ? row : col)-1)/2 + 1;     // 圈数
        for (int i = 0; i < circle; i++)
        {
            // 从左向右打印
            for(int j = i; j < col - i; j++)
                res.push_back(matrix[i][j]);
            // 从上向下打印每个数据
            for(int k = i+1; k < row - i; k++)
                res.push_back(matrix[k][col - 1 - i]);
            // 从右往左打印
            for(int m = col - i - 2; (m>=i)&&(row-i-1!=i); m--)
                res.push_back(matrix[row-i-1][m]);
            // 从下往上
            for(int n = row - i - 2; (n>i)&&(col-i-1 != i); n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
