#include <iostream>
#include "StrVec.h"
using namespace std;

int main()
{
    StrVec sv;
    sv.push_back("So");
    sv.push_back("Good");
    for (auto &m : sv)
        cout << m << " ";
    cout << endl;
    return 0;
}
