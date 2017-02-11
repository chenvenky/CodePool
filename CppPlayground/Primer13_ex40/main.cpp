#include <iostream>
#include "StrVec.h"
using namespace std;
/** \brief
Exercise  13.40:  Add  a  constructor  that  takes  an
initializer_list<string> to your StrVec class.
 *
 * \param
 * \param
 * \return
 *
 */

int main()
{
    StrVec sv, sv2{"So", "fun"};
    sv.push_back("So");
    sv.push_back("Good");
    for (auto &m : sv)
        cout << m << " ";
    cout << endl;

    for (auto &m : sv2)
        cout << m << " ";
    cout << endl;
    return 0;
}
