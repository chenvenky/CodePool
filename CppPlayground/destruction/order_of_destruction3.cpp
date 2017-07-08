/*************************************************************************
* File Name: order_of_destruction3.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: 2017/7/8 13:40:29
*
* Description: 
    析构函数的顺序问题 3: 声明的逆序，从下往上，从右向左
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

struct C : public A, public B
{
    virtual ~C()
    {
        printf("C dtor\n"); 
    }
}; 

int main()
{
    C* c = new C; 
    delete c; 
    printf("\n"); 

    return 0; 
}
