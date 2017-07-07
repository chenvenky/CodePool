#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> dic(length, 0);
        if (length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            if(dic[numbers[i]] == 1)
            {
                *duplication = numbers[i];
                return true;
            }
            dic[numbers[i]] = 1;
        }

        return false;
    }
};

// 不开辟新空间（数组，bool数组）的优雅解法
// 但是可能出现数组越界
class Solution2 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index >= length)
                index -= length;

            if(numbers[index] >= length)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] += length;
        }

        return false;
    }
};

// 用 - length 代替 + length 避免数组越界
class Solution3 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index < 0)
                index += length;

            if(numbers[index] < 0)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] -= length;
        }

        return false;
    }
};

// 用 乘以 -1 法， 避免数组越界
class Solution4 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index < 0)
                index *= -1;

            if(numbers[index] < 0)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] *= -1;
        }

        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
