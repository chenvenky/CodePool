/*************************************************************************
* File Name: order_of_destruction2.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: 2017/7/8 13:40:29
*
* Description: 
    析构函数的顺序问题 2
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct A
{
    virtual ~A() 
    {
        printf("A dtor\n");
    }
};

struct B
{
    virtual ~B()
    {
        printf("B dtor\n"); 
    }
};

struct  C : virtual public A, virtual public B
{
    virtual ~C()
    {
        printf("C dtor"); 
    }
}; 

struct D : virtual public A, virtual public B
{
    ~D() 
    {
        printf("D dtor\n");
    }
};

struct E: public C, public D, virtual public B
{
    ~E()
    {
        printf("E dtor\n"); 
    }
};

int main()
{
    E* e = new E; 
    delete e;  

    return 0; 
}
