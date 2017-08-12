/*************************************************************************
* File Name: static-log.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: http://chenwenke.cn
* Created Time: Sat 12 Aug 2017 06:33:02 AM PDT
*
* Description: 
    静态化并不是单例（Singleton）模式。
    问题：
            1. 静态成员变量初始化顺序不依赖构造函数，而是根据编译器，没法保证初始化顺序。 （极端情况： 有 a, b两个成员对象， b需要把 a 作为初始化参数传入）。
            2. 最严重的问题，失去了面向对象的重要特征 --- “多态”， 静态成员方法不可能是 virtual的 Log类的子类没法享受“多态”带来的便利。 
 ************************************************************************/
#include "log.h"

class log
{
public:
    static void Write(char const *logline); 
    static bool SaveTo(char const *filename); 

private:
    static std::list<std::string> m_data; 
}; 

std::list<std::string> log::m_data;  
