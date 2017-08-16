/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Wed 16 Aug 2017 08:09:33 AM PDT
*
* Description: 
    求 1+2+3+...+n 。静态成员 + 构造函数。     
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

class Temp
{
public:
    Temp()
    {
        N++; 
        Sum += N; 
    }

    static void Reset()
    {
        N = 0; 
        Sum = 0; 
    }

    static int GetSum()
    {
        return Sum; 
    }

private:
    static int N; 
    static int Sum; 
}; 

int Temp::N = 0; 
int Temp::Sum = 0; 

class Solution
{
public:
    int Sum_Solution(int n)
    {
        Temp::Reset(); 
        Temp* ret = new Temp[n]; 
        delete[] ret; 

        return Temp::GetSum(); 
    }
}; 

int main()
{

    return 0; 
}
