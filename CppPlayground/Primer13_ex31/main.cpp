#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/**********************************************************
Question Description:
 Give your class a < operator and define a vector of
HasPtrs. Give that vector some elements and then sort the vector.
C++ Primer, Fifth Edition
Note when swap is called.
***********************************************************/

class HasPtr
{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);

    HasPtr(const string &s = string()):ps(new string(s)), i(0) { }
    HasPtr(const HasPtr&hp): ps(new string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(HasPtr tmp)
    {
        swap(*this, tmp);   // 没有用自身的 swap 函数
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

    // swap 函数

    ostream& display(ostream &os)
    {
        os << *(this->ps) << "\t" << this->i << endl;
        return os;
    }
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "I have run swap(HasPtr&,HasPtr&)" << endl;
}

inline
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main()
{
    HasPtr hp1("Do More"), hp2("Say Less");
    vector<HasPtr> vec{string("So Fun"), string("So Good")};
    vec.push_back(hp1);
    vec.push_back(hp2);

     for (auto &elem : vec)
        elem.display(cout);

    sort(vec.begin(), vec.end());
    for (auto &elem : vec)
        elem.display(cout);

    return 0;
}
