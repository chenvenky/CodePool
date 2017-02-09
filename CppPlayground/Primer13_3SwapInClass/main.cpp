#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        知识点总结
### 其它知识点参考 CopyContructor
除了定义拷贝控制成员，管理资源的类通常还定义一个名为 swap 的函数。
对于那些与重排元素顺序的算法一起使用的类。这类算法在需要交换两个
元素时会调用swap。 我们可以重载自己的 swap。 另外，定义swap 的类
通常用 swap 来定义它们的赋值运算符。

***********************************************************/
class HasPtr
{
public:
    // 重载标准库里定义的 swap
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // 对 ps 指向的 string, 每个 HasPtr 对象都有自己的拷贝
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) { } // 拷贝构造函数
    // 用 swap 函数实现拷贝赋值运算符
    HasPtr& operator=(HasPtr p);  // 注意这里用的是值传递
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

inline
void swap(HasPtr &lhs, HasPtr&rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);       // 交换指针，而不是 string 数据
    swap(lhs.i, rhs.i);         // 交换 int 成员
}

// 用 swap 函数实现拷贝赋值运算符
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // 交换左侧运算对象和局部变量 rhs 的内容
    swap(*this, rhs);       // rhs 现在指向本对象曾经使用的内存
    return *this;           // rhs 被销毁， 从而 delete 了 rhs 中的指针
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
