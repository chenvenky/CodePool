/*************************************************************************
* File Name: meyers-singleton-log.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Sat 12 Aug 2017 07:09:39 AM PDT
*
* Description: 
    懒汉模式（局部静态变量-最佳版） --- 在 VS2015版本及以上， gcc 4.6  线程安全   
 ************************************************************************/

class Log
{
public:
    static Log& Instance()
    {
        static Log theLog;
        return theLog; 
    }

    virtual void Write(char const * logline); 
    virtual bool SaveTo(char const *filename); 

    // more (non-static) function here
private:
    Log();              // ctor is hidden
    Log(Log const&);    // copy ctor is hidden
    Log& operator=(Log const&);     // assign op is hidden
    ~Singleton();                   // dtor hidden

    static std::list<std::string> m_data; 
}; 


