#include <iostream>
#include <vector>
using namespace std;

/************************************************
        理解拷贝控制成员与析构函数
************************************************/
struct X
{
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X&){ cout << "X& operator=(const X&)" << endl; return *this; }
    ~X(){ cout << "~X()" << endl; }
};

void refX(X &x1)
{

}

void valX(X x1)
{

}

int main()
{
    X x1;
    //vector<X> vec;            // 容器
    //vec.push_back(x1);

    //X x2(x1);         // 直接初始化
    //X x3=x1;          // 拷贝构造初始化
    //X x4;             // 拷贝赋值
    //x4 = x1;
    //refX(x1);         // 引用
    valX(x1);         // 值调用 -->拷贝构造
    //X *x7 = new X(x1);
    //delete x7;
    cout << "Hello world!" << endl;
    return 0;
}
