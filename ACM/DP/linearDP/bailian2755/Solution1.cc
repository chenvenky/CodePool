/*************************************************************************
* File Name: Solution1.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 16 Aug 2017 05:17:01 AM PDT
*
* Description: 
    递归解法    
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

int arr[30]; 

// 从前 k 种物品中选择一些，凑成体积 w 的做法数目。 
int Ways(int w, int k)
{
    if(w == 0)
        return 1; 
    if(k <= 0)
        return 0; 
    return Ways(w, k-1) + Ways(w-arr[k], k-1); 
}

int main()
{
    int n; 
    cin >> n; 
    for(int i = 1; i <= n; i++)
        cin >> arr[i]; 
    cout << Ways(40, n) << endl; 

    return 0; 
}
