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

### 拷贝赋值函数
拷贝赋值运算符接受一个与其所在类相同类型的参数（与拷贝构造函数相同）为了与内
置类型的赋值保持一致，赋值运算符通常返回一个指向其左侧运算对象的引用。另外值
得注意的是，标准库通常要求保存在容器中的类型要具有赋值运算符，且其返回值是左
侧运算对象的引用（这一点在自定义的类在使用容器时尤其重要）。

Best Practice: 赋值运算符通常应该返回一个指向其左侧运算符对象的引用。

### 析构函数
在一个构造函数中，成员的初始化是在函数体执行之前完成的，且按照它们在类中出现
的顺序进行初始化。在一个析构函数中，首先执行函数体，然后销毁成员。成员按初始
化顺序的逆序进行销毁。通常，析构函数释放对象在生存期分配的所有资源。
Note: 隐式销毁一个内置指针类型的成员不会 delete 它所指向的对象。
与普通指针不同，智能指针是类类型，所以具有析构函数。因此，和普通指针不同的是
智能指针成员在析构阶段会被自动销毁。
Note: 当指向一个对象的引用或指针离开作用域时，析构函数不会进行。
认识到析构函数体自身并不直接销毁成员是非常重要的。 成员是在析构函数体之后隐含
的析构阶段中被销毁的。在整个对象销毁过程中，析构函数体是作为成员销毁步骤之外
的另一部分而进行的。

### 三/五法则
* 需要析构函数的类也需要拷贝和赋值操作
* 需要拷贝操作的类也需要赋值操作，反之亦然
* 析构函数不能是删除的成员
本质上，当不可能拷贝，赋值或销毁类的成员时，类的合成拷贝控制成员就被定义为删除的。

题目： C++Primer 13.5 给定下面的类框架，编写一个拷贝构造函数, 拷贝所有成员。你
的构造函数应该动态分配一个新的 string, 并将对象拷贝到 ps 指向的位置，而不是拷贝
ps 本身；为类添加拷贝赋值函数； 为类添加析构函数；

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
    // 拷贝赋值函数
    HasPtr& operator=(const HasPtr& p)
    {
        ps = new std::string(*p.ps);
        i = p.i;
        return *this;
    }
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
