#include <iostream>
#include <string>
using namespace std;

int FirstNotRepeatingChar(string str)
{
    if (str.length() == 0)
        return -1;
    unsigned int hashTime[256] = {0};
    for(int i = 0; i < str.length(); i++)
        hashTime[str[i]]++;

    for(int i = 0; i < str.length(); i++)
        if(hashTime[str[i]]==1)
        return i;
    return -1;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
