/*************************************************************************
* File Name: code.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Fri 11 Aug 2017 06:15:20 AM PDT
*
* Description: 
    最大连续子序列，小变形。    
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

const int maxn = 10000 + 5; 
int arr[maxn]; 

int main()
{
    int K; 
    while(scanf("%d", &K) != EOF && K)
    {
        for(int i = 0; i < K; i++)
            scanf("%d", &arr[i]); 

        int sum = 0; 
        int bestAns = 0; 
        int begin = arr[0];
        int end = arr[K-1]; 
        int pos = arr[0]; 
        for(int i = 0; i < K; i++)
        {
            if(sum < 0)
            {
                sum = arr[i]; 
                pos = arr[i]; 
            }
            else
            {
                sum += arr[i]; 
            }
            if(bestAns < sum)
            {
                begin = pos; 
                end = arr[i]; 
                bestAns = sum; 
            }
        }
        if(bestAns == 0)
        {
            for(int i = 0; i < K; i++)
            {
                if(arr[i] == 0)
                {
                    begin = 0; 
                    end = 0; 
                    break; 
                }
            }
        }
        printf("%d %d %d\n", bestAns, begin, end); 
    }
    return 0; 
}
