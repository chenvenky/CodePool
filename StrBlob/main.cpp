#include <iostream>
#include "StrBlob.h"
using namespace std;

int main()
{
    StrBlob blob {"So", "Fun", "So", "Good"};
    StrBlobPtr blobPtr(blob);
    cout << blob.front() << endl;
    blobPtr.incr();
    cout << blobPtr.deref() << endl;
    blobPtr = blob.begin();
    cout << blobPtr.deref() <<endl;
    cout << blob.back() << endl;
    return 0;
}
