#include <iostream>
#include <string>
using namespace std;

/**********************************************************
Question Description:
 Write and test a swap function for your value like version of
HasPtr(Primer13_2_1ClassThatLikeValues). Give your swap a print
 statement that notes when it is executed.
***********************************************************/
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
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

inline void swap(HasPtr&lhs, HasPtr&rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "I have run swap(HasPtr&, HasPtr&)" << endl;
}
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
    HasPtr hp2("So Fun");
    hp1.display(cout);
    hp2.display(cout);
    swap(hp1, hp2);
    hp1.display(cout);
    hp2.display(cout);
    return 0;
}
