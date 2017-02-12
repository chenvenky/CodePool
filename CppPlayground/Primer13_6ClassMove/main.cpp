#include <iostream>
#include <vector>
using namespace std;
/** \brief
 *
 *
 *
 *
 *
 */

int f() { return 1; }
int main()
{
    vector<int> v1(100);
    int &&r1 = f();
    int &r2 = v1[0];
    int &r3 = r1;
    int &&r4 = v1[0] * f();
    cout << "r1:\t" << r1 << endl;
    cout << "r2:\t" << r2 << endl;
    cout << "r3:\t" << r3 << endl;
    cout << "r4:\t" << r4 << endl;
    return 0;
}
