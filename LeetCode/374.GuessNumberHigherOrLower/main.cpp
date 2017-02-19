#include <iostream>
using namespace std;

int guessNumber(int n)
{
    int maxNumber = n;
    int minNumber = 1;
    while (true)
    {
        int midNumber = (maxNumber - minNumber)/2 + minNumber;
        int res = guess(midNumber);
        if (res == 0)
        {
            return midNumber;
        }
        else if (res == 1)
        {
            minNumber = midNumber + 1;
        }
        else
        {
            maxNumber = midNumber - 1;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

