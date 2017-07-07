#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void PrintNumber(char* number);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; i++)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if(!isBeginning0)

        {
            printf("%c", number[i]);
        }
    }
}
