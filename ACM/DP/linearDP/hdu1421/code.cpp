/*************************************************************************
* File Name: code.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 11 Aug 2017 06:45:23 AM PDT
*
* Description: 
    
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
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 2000+5; 
int dp[maxn][maxn/2]; 
int arr[maxn]; 

int main()
{
    int n, k; 
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]); 
        sort(arr, arr + n); 

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= k; j++)
                dp[i][j] = INT_MAX; 

        for(int i = 0; i < n; i++)
            dp[i][0] = 0; 
        dp[1][1] = (arr[1] - arr[0]) * (arr[1] - arr[0]); 

        for(int i = 2; i < n; i++)
        {
            for(int j = 1; j <= (i+1)/2 && (j <= k); j++)
            {
                int tmp = arr[i] - arr[i-1]; 
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + tmp * tmp); 
            }
        }
        printf("%d\n", dp[n-1][k]); 
    }
    return 0; 
}
