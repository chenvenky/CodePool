/*************************************************************************
* File Name: Solution.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Thu 24 Aug 2017 06:35:52 AM PDT
*
* Description: 
    字符流中第一个不重复的字符。    
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

class Solution
{
public:
    // Insert one char from stringstream
    void Insert(char ch)
    {
        cnt[ch]++;
        if(cnt[ch] == 1)
            qu.push(ch); 
    }

    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!qu.empty() && cnt[qu.front()] >= 2)
            qu.pop(); 
        if(!qu.empty())
            return qu.front(); 
        else
            return '#'; 
    }

private:
    unsigned int cnt[300]{0}; 
    queue<char> qu; 
}; 


int main()
{

    return 0; 
}
