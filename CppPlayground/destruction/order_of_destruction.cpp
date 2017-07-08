/*************************************************************************
* File Name: order_of_destruction.cpp
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: 2017/7/8 13:40:29
*
* Description: 
    析构函数的顺序问题 1    
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct A1
{
    virtual ~A1() 
    {
        printf("A1 dtor\n");
    }
};

struct A2 : A1
{
    virtual ~A2()
    {
        printf("A2 dtor\n"); 
    }
};

struct  A3 : A2
{
    virtual ~A3()
    {
        printf("A3 dtor"); 
    }
}; 

struct B1
{
    ~B1() 
    {
        printf("B1 dtor\n");
    }
};

struct B2 : B1
{
    ~B2()
    {
        printf("B2 dtor\n"); 
    }
};

struct  B3 : B2
{
    ~B3()
    {
        printf("B3 dtor"); 
    }
}; 

int main()
{
    A1* a = new A3; 
    delete a; 
    printf("\n"); 

    B1* b = new B3; 
    delete b; 
    printf("\n"); 

    B3* b2 = new B3; 
    delete b2;  

    return 0; 
}
