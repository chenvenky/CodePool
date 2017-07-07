#include <iostream>
using namespace std;

class Base
{
public:
    static int b1;
};

class Devies : public Base
{
public:
    static int b1;
};

int Base::b1=10;
int Devies::b1=12;

int main()
{
    cout << Base::b1 << endl;
    cout << Devies::b1 << endl;
    cout << Base::b1 <<  endl;
    cout << Devies::b1 << endl;
    return 0;
}
