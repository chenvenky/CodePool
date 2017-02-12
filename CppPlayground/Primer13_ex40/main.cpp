#include <iostream>
#include "StrVec.h"
using namespace std;
/** \brief
Exercise  13.40:  Add  a  constructor  that  takes  an
initializer_list<string> to your StrVec class.
 *
 * 左值引用绑定的都是持久值， 而右值引用绑定临时值。
 * 右值引用指向将要被销毁的对象。因此，我们可以从绑
 * 定到右值引用的对象“窃取”状态。
 * 在移动操作之后。移动源对象必须保持有效的，可析构
 * 的状态，但是用户不能对其值进行任何假设。
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

    const int &i = 3;       // 这种情况是允许的， 因为我们不能通过 i 改变临时量 3 的值。
    cout << i << endl;
    return 0;
}
