#include <iostream>
#include "StrBlob.h"
using namespace std;

int main()
{
    StrBlob SS1{"Do", "More", "Say", "Less"};
    StrBlob SS2 = SS1;

    SS2[3] = "Best";

    if (SS1 > SS2)
    {
        for (ConstStrBlobPtr iter=SS1.cbegin(); iter < SS1.cend(); iter.incr())
            cout << iter.deref() << " ";
        cout << endl;
    }

    StrBlobPtr iter(SS2);
    cout << iter[3] << endl;
    return 0;
}
