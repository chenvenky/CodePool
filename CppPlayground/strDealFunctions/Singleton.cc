/*************************************************************************
* File Name: Singleton.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Sun 20 Aug 2017 08:44:13 PM CST
*
* Description: 
    单例模式    
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Log
{
public:
    static Log& Instance()
    {
        static Log theLog; 
        return theLog; 
    }

    virtual void Write(char const* logline); 
    virtual void SaveTo(char const* filename); 

    // more (non-static) function here
private:
    Log();      // ctor is hidden
    Log(Log const&);    // copy ctor is hidden
    Log& operator=(Log const&);     // assign op is hidden
    
    static std::list<std::string> m_data;           
}; 

int main()
{

    return 0; 
}
