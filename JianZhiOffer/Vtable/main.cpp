#include <iostream>
using namespace std;

class Base1 {
private:
    virtual void f() { cout << "Base1::f" << endl; }
    virtual void g() { cout << "Base1::g" << endl; }
    virtual void h() { cout << "Base1::h" << endl; }
};

class Base2 {
public:
    virtual void f() { cout << "Base2::f" << endl; }
    virtual void g() { cout << "Base2::g" << endl; }
    virtual void h() { cout << "Base2::h" << endl; }
};

class Base3 {
    virtual void f() { cout << "Base3::f" << endl; }
    virtual void g() { cout << "Base3::g" << endl; }
    virtual void h() { cout << "Base3::h" << endl; }
};

class Derive: public Base1, public Base2, public Base3 {
public:
    virtual void f() { cout << "Derive::f" << endl; }
    virtual void g1() { cout << "Derive::g1" << endl; }
};

typedef void(*Fun)(void);   // 定义函数指针 Fun

int main()
{
    Fun pFun = NULL;
    Derive d;
    long long** pVtab=(long long**)&d;
    // Base1's vtable
    pFun = (Fun)pVtab[1][1];
    pFun();
}
