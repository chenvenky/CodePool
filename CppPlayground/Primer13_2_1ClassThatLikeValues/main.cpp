#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        知识点总结
### 行为像值的类(Classes that act like values)
/CopyConstructor中的 HasPtr 类 更改成 行为像值的类
* 定义一个拷贝构造函数，完成 string 的拷贝，而不是拷贝指针
* 定义一个析构函数来释放 string
* 定义一个拷贝赋值运算符来释放对象当前的 string， 并从右侧
  运算对象拷贝 string

#### 类值拷贝赋值运算符
    赋值运算符通常组合了析构函数和构造函数的操作。类似析构
    函数，赋值操作会销毁左侧运算对象的资源。 类似拷贝构造
    函数，赋值操作会从右侧运算对象拷贝数据。【重要：】这些
    操作要以正确的顺序进行，即使是一个对象赋予它自身，也保
    证正确。 而且，如果有可能，我们编写的赋值运算符还应该是
    异常安全的 ---- 当异常发生时能将左侧运算对象置于一个有
    意义的状态。

再强调一下，当你编写赋值运算符时，有两点需要记住：
* 如果将一个对象赋予它自身，赋值运算符必须能正常工作
* 大多数赋值运算符组合了析构函数和拷贝构造函数的工作

***********************************************************/
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // 对 ps 指向的 string, 每个 HasPtr 对象都有自己的拷贝
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) { } // 拷贝构造函数
    // 拷贝赋值函数
    HasPtr& operator=(const HasPtr& p);
    // 用于调试的 输出函数
    ostream& display(ostream&);
    ~HasPtr()               // 用于释放 new 分配的内存的析构函数
    {
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

// 拷贝赋值函数的实现
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);    // 拷贝底层 string
    delete ps;              // 释放旧内存
    ps = newp;              // 从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;           // 返回本对象
}
// 输出函数的实现
ostream& HasPtr::display(ostream&os)
{
    os << *(this->ps) << "\t" << this->i << endl;
    return os;
}
int main()
{
    string s("copy constructor");
    HasPtr hp1(s);
    HasPtr hp2=hp1; // 拷贝初始化
    HasPtr hp3; hp3 = hp1;  // 拷贝赋值
    hp1.display(cout);
    hp2.display(cout);
    hp3.display(cout);
    return 0;
}
