#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        知识点总结
### 定义行为像指针的类( Defining classes that act like pointers)
/CopyConstructor中的 HasPtr 类 更改成 行为像指针的类
    令一个类展现类似指针的行为的最好方法是使用 shared_ptr 来管理类
中的资源。
    但是，有时我们希望直接管理资源。在这种情况下，使用引用计数(reference
 count)就很有用了。

#### Reference Counts
Reference counting works as follows:
• In addition to initializing the object, each constructor (other than the copy
constructor) creates a counter. This counter will keep track of how many objects
share state with the object we are creating. When we create an object, there is
only one such object, so we initialize the counter to 1.
• The copy constructor does not allocate a new counter; instead, it copies the
data members of its given object, including the counter. The copy constructor
increments this shared counter, indicating that there is another user of that
object’s state.
• The destructor decrements the counter, indicating that there is one less user of
the shared state. If the count goes to zero, the destructor deletes that state.
• The copy-assignment operator increments the right-hand operand’s counter and
decrements the counter of the left-hand operand. If the counter for the left-hand
operand goes to zero, there are no more users. In this case, the copy-
assignment operator must destroy the state of the left-hand operand.

计数器的实现方式： 将计数器保存在动态内存中，当创建一个对象时，我们也分配一个新的
计数器。当拷贝或赋值对象时，我们拷贝指向计数器的指针。

***********************************************************/
class HasPtr
{
public:
    // 构造函数分配新的 string 和新的计数器， 将计数器置为 1
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }

    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)),i(p.i),use(p.use){ ++*use; }

    // 拷贝赋值函数 递增右侧计数器，递减左侧计数器（到0释放）
    HasPtr& operator=(const HasPtr& p);

    ostream& display(ostream&);

    // 到 0 释放
    ~HasPtr();               // 用于释放 new 分配的内存的析构函数
private:
    std::string *ps;
    int i;
    std::size_t *use;           // 用来记录有多少个对象共享 *ps 的成员
};

// 拷贝赋值函数 递增右侧计数器，递减左侧计数器（到0释放）
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;             // 递增右侧运算符对象的引用计数
    if (--*use == 0)        // 然后递减本对象的引用计数
    {
        delete ps;          // 如果没有其他用户
        delete use;         // 释放本对象分配的成员
    }
    ps = rhs.ps;            // 将数据从 rhs 拷贝到本对象
    i = rhs.i;
    use = rhs.use;
    return *this;           // 返回本对象
}

// 到 0 释放
HasPtr::~HasPtr()
{
    if (--*use == 0)        // 推出作用域时，计数会减一，如果引用计数变为 0
    {
        delete ps;          // 释放 string 内存
        delete use;         // 释放计数器内存
    }
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
