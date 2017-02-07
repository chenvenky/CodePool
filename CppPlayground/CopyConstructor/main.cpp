#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        知识点总结
### 拷贝构造函数（copy constructor）
每个成员的类型决定了它如何拷贝： 对类类型的成员，会使用其拷贝构造函数来拷贝；
内置类型的成员则直接拷贝。

拷贝初始化(copy initialization)时, 我们要求编译器将右侧运算对象拷贝到正在创建
的对象中，如果需要的话还要进行类型转换。 拷贝初始化不仅在我们用=定义变量时会
发生，下列情况也会发生。
	• 将一个对象作为实参传递给一个非引用类型的形参
	• 从一个返回类型为非引用类型的函数返回一个对象
	• 用花括号列表初始化一个数组中的元素或一个聚合类中的成员。


题目： C++Primer 13.5 给定下面的类框架，编写一个拷贝构造函数, 拷贝所有成员。你
的构造函数应该动态分配一个新的 string, 并将对象拷贝到 ps 指向的位置，而不是拷贝
ps 本身；

***********************************************************/
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { } // 拷贝构造函数
    // 用于调试的 输出函数
    ostream& display(ostream&);
    ~HasPtr()               // 用于释放 new 分配的内存的析构函数
    {
        delete this->ps;
    }
private:
    std::string *ps;
    int i;
};

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
    HasPtr hp2 = hp1;
    hp1.display(cout);
    hp2.display(cout);
    return 0;
}
