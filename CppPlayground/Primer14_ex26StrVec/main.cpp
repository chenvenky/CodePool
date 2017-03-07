#include "StrVec.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    StrVec vec;
    vec.reserve(6);
    std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;

    vec.reserve(4);
    std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;

    vec.push_back("hello");
    vec.push_back("world");

    vec.resize(4);

    for (auto i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << std::endl;
    std::cout << "-EOF-" << std::endl;

    StrVec vec_list{"Do", "More", "Say", "Less"};

    for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    return 0;
}
