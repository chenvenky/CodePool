/*************************************************************************
* File Name: String.h
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://chenwenke.cn
* Created Time: Mon 21 Aug 2017 03:47:21 PM CST
*
* Description: 
    String 类的简单实现
    1. 只在构造函数里调用 new char[], 只在析构函数里调用 delete[]. 
    2. 赋值操作符采用了 《C++编程规范》推荐的现代写法
    3. 每个函数都只有一两行代码，没有条件判断
    4. 析构函数不必检查 data_是否为 NULL
    5. 构造函数 String(const char* str)没有检查 str 的合法性， 这是一个
        永无止境的争论话题。这里在初始化列表里就用到了 str, 因此在函数体
        内调用 assert()是无意义的。     
 ************************************************************************/

#include <utility>
#include <string.h>

class String
{
public:
    String()
        : data_(new char[1])
        {
            *data_ = '\0'; 
        }

    String(const char* str)
        : data_(new char[strlen(str) + 1])
        {
            strcpy(data_, str); 
        }

    String(const String& rhs)
        : data_(new char[rhs.size() + 1])
        {
            strcpy(data_, rhs.c_str()); 
        }

    ~String()
    {
        delete[] data_; 
    }

    String& operator=(String rhs)   // yes, pass-by-value
    {
        swap(rhs); 
        return *this; 
    }

    size_t size() const
    {
        return strlen(data_); 
    }

    const char* c_str() const
    {
        return data_; 
    }

    void swap(String& rhs)
    {
        std::swap(data_, rhs.data_); 
    }

private:
    char* data_; 
}; 


