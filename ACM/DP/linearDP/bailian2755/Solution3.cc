/*************************************************************************
* File Name: Solution3.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 16 Aug 2017 06:05:15 AM PDT
*
* Description: 
    动态规划    
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

const int maxn = 41; 

int main()
{
    int n; 
    int i, j, input; 
    int sum[maxn]; 

    for(i = 0; i < maxn; i++)
        sum[i] = 0; 
    cin >> n; 
    for(i = 0; i < n; i++)
    {
        cin >> input;
        for(j = 40; j >= 1; j--)
            if(sum[j] > 0 && j + input <= 40)
                sum[j+input] += sum[j];     // 如果j有sum[j]种方式可达，则每种方式加上input就可达j+input
                sum[input]++;
    }
    cout << sum[40] << endl; 
    return 0; 
}
