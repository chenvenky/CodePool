// log.h
#ifndef __LOG_H__
#define __LOG_H__

#include <list>
#include <string>

class Log
{
public:
    virtual void Write(char const *logline); 
    virtual bool SaveTo(char const *filename); 
private:
    std::list<std::string> m_data; 
}; 

#endif  // __LOG_H__
