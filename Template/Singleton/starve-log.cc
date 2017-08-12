/*************************************************************************
* File Name: starve-log.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Sat 12 Aug 2017 06:44:16 AM PDT
*
* Description: 
    饿汉模式： 是指单例实例在程序运行时被立即执行初始化。     
 ************************************************************************/

class Log
{
public:
    static Log* Instance()
    {
        return &m_pInstance; 
    }

    virtual void Write(char const *logline); 
    virtual bool SaveTo(char const *filename); 

private:
    Log();              // ctor is hidden
    Log(Log const&)     // copy ctor is hidden

    static Log m_pInstance; 
    static std::list<std::string> m_data; 
}

// in log.cc we have to add 
Log Log::m_pInstance; 


/********************************************************
问题：
    1. 静态成员变量初始化顺序没法保证。
    2. 假如有两个单利模式类 ASingleton 和 BSingleton, 某天
    你想在 BSingleton的构造函数中使用 ASingleton实例， 这
    就出问题了。 因为 BSingleton m_pInstance静态对象可能先
    ASingleton 一步调用初始化构造函数，结果 ASingleton::Instance()
    返回的就是一个未初始化的内存区域，程序还没跑就直接崩溃掉。 
*********************************************************/


