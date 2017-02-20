#include <iostream>
#include "StrVec.h"
using namespace std;

int main()
{
    StrVec strv{"Do", "More", "Say", "Less"};
    for (auto &i : strv)
        cout << i << " ";
    cout << endl;
    return 0;
}
