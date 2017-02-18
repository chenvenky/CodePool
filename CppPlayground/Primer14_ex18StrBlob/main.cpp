#include <iostream>
#include "StrBlob.h"
using namespace std;

int main()
{
    StrBlob sb{"Do", "More", "Say", "Less"};
    for (auto iter = sb.cbegin(); iter != sb.cend(); iter.incr())
        cout << iter.deref() << " ";
    cout << endl;
    return 0;
}
