/*************************************************************************
* File Name: gamma-singleton-log.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Sat 12 Aug 2017 06:56:46 AM PDT
*
* Description: 
    懒汉模式： 单例实例只在第一次被使用时进行初始化。     
 ************************************************************************/
class Log
{
public:
    static Log* Instance()
    {
        if(!m_pInstance)
            m_pInstance = new Log; 
        return m_pInstance; 
    }

    virtual void Write(char const *logline); 
    virtual void SaveTo(char const *filename); 

    virtual bool destructor()
    {
        // ... release resource

        if(NULL != m_pInstance)
        {
            delete m_pInstance; 
            m_pInstance = NULL; 
        }
    }
private:
    Log();              // ctor is hidden
    Log(Log const&);    // copy ctor is hidden

    static Log* m_pInstance; 
    static std::list<std::string> m_data; 
}; 

// in log.cc we have to add
Log::m_pInstance = NULL; 
