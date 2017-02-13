#include <iostream>
#include "HasPtr.h"
using namespace std;

int main()
{
    HasPtr hp1("Do More"), hp2("Say Less"), *pp = new HasPtr("Less is More");
    hp1 = hp2;
    hp1 = std::move(*pp);
    return 0;
}
