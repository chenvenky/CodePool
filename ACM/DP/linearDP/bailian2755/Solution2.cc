/*************************************************************************
* File Name: Solution2.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 16 Aug 2017 05:22:54 AM PDT
*
* Description: 
    动归解法。    
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

int arr[30]; 
int ways[40][25];   // ways[i][j] 表示从前 j 个物品中凑出体积 i 的方案数。 

int main()
{
    int n; 
    cin >> n; 
    memset(ways, 0, sizeof(ways)); 
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i]; 
        ways[0][i] = 1; 
    }
    ways[0][0] = 1; 
    for(int w = 1; w <= 40; w++)
    {
        for(int k = 1; k <= n; k++)
        {
            ways[w][k] = ways[w][k-1]; 
            if(w >= arr[k])
                ways[w][k] += ways[w-arr[k]][k-1]; 
        }
    }

    cout << ways[40][n] << endl; 
    return 0; 
}
