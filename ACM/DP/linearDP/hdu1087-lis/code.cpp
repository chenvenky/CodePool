/*************************************************************************
* File Name: code.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 11 Aug 2017 05:29:24 AM PDT
*
* Description: 
    lis: 最长上升序列变形。    
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
#include <algorithm>
using namespace std;

const int maxn = 1000+5; 

int arr[maxn]; 
int dp[maxn]; 

int main()
{
    int n; 
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        memset(dp, 0, sizeof(dp)); 
        
        int bestAns = arr[0]; 
        for(int i = 0; i < n; i++)
        {
            dp[i] = arr[i]; 
            for(int j = 0; j < i; j++)
            {
                if(arr[i] > arr[j])
                    dp[i] = max(dp[i], arr[i]+dp[j]); 
            }
            if(bestAns < dp[i])
                bestAns = dp[i]; 
        }

        printf("%d\n", bestAns); 
    }

    return 0; 
}
