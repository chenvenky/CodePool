#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <algorithm>
using namespace std;

void merge_sort(int* A, int left, int right, int * T)   // right 为尾后元素
{
	if(right-left > 1)
    {
        int mid = left + (right - left) / 2;    // 划分
        int pos1 = left, pos2 = mid, pos = left;
        merge_sort(A, left, mid, T);     // 递归求解
        merge_sort(A, mid, right, T);     // 递归求解
        while(pos1 < mid || pos2 < mid)
        {
            if(pos2 >= right || (pos1 < mid && A[pos1] <= A[pos2]))   // 从左半数组复制到临时空间
                T[pos++] = A[pos1++];
            else
                T[pos++] = A[pos2++];                    // 从右半数组复制到临时空间
        }
        for(pos = left; pos < right; pos++) A[pos] = T[pos];         // 从辅助空间复制回 A 数组。
    }
}

// quick sort

// 划分函数
int Partition(int data[], int length, int start, int end);

void quick_sort(int data[], int length, int start, int end)
{
    // end 是最后一个元素的下标
    if(start == end)
        return;
    int index = Partition(data, length, start, end);
    if(index > start)
        quick_sort(data, length, start, index-1);
    if(index < end)
        quick_sort(data, length, index+1, end);
}

int Swap(int& a, int& b);    // 交换函数
int Partition(int data[], int length, int start, int end)   // 划分函数
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw runtime_error("Invalid Parameters");
    // int index = RandomInRange(start, end);
    // swap(&data[index], &data[end]);
    int small = start - 1;
    for(int index = start; index < end; index++)
    {
        if(data[index] < data[end])
        {
            small++;
            if(small != index)
                Swap(data[index], data[small]);
        }
    }
    small++;
    Swap(data[small], data[end]);
    return small;
}

int Swap(int& a, int& b)    // 交换函数
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 计数排序
void num_sort(int data[], int begin, int end, int length)
{
    if(data == NULL || length <= 0 || begin < 0 || end >= length)
        throw runtime_error("Invalid Parameters");
    vector<int> count(100, 0);      // 假设排序的数字是 0 ~ 99 之间的整数
    for(int i = 0; i < 100; i++)
        count[i] = 0;
    for(int i = begin; i <= end; i++)
        count[data[i]]++;
    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];
    vector<int> T(length, 0);
    for(int i = begin; i <= end; i++)
        T[i] = data[i];
    for(int i = begin; i <= end; i++)
    {
        data[count[T[i]]] = T[i];
        count[T[i]]--;
    }
}

int fastPow(int base, int num)
{
    if(num < 0)
        throw runtime_error("Invalid Input");
    else if(num == 0)
        return 1;

    if(num & 1)
        return base * fastPow(base * base, num >> 1);
    else
        return fastPow(base * base, num >> 1);
}

int main()
{
    cout << fastPow(0, 0) << endl;
    return 0;
}
