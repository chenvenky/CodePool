## 排序算法与选择小笔记

#### 基于比较的排序：时间复杂度上界 (N lg N) 
- 插入排序和冒泡排序 特点：简单，原址排序，而且具有稳定性。时间复杂度 N^2.

```cpp
// 插入排序
void InsertSort(vector<int> arr, int n)
{
	for(int j = 1; j < n; j++)
	{
		int key = arr[j]; 
		// Insert A[j] into the sorted sequece A[1..j-1]
		i = j - 1; 
		while(i > 0 && arr[i] > key)	// search the right pos 
		{
			arr[i+1] = arr[i]; 		// move elements 
			i = i - 1; 			
		}
		arr[i+1] = key; 
	}
}
```

<br/>

- 归并排序： 分治思想的典型。 需要借助一个存结果和归并的额外数组。可以用来求逆序数。 时间复杂度 N lg N.

```cpp
void merge_sort(int* A, int left, int right, int * T)   // right 为尾后元素
{
	if(right-left > 1)
    {
        int mid = left + (right - left) / 2;    // 划分
        int pos1 = left, pos2 = mid, pos = left;
        merge_sort(A, left, mid, T);     // 递归求解
        merge_sort(A, mid, right, T);     // 递归求解
        while(pos1 < mid || pos2 < right)
        {
            if(pos2 >= right || (pos1 < mid && A[pos1] <= A[pos2]))   // 从左半数组复制到临时空间
                T[pos++] = A[pos1++];
            else
                T[pos++] = A[pos2++];                    // 从右半数组复制到临时空间
        }
        for(pos = left; pos < right; pos++) A[pos] = T[pos];         // 从辅助空间复制回 A 数组。
    }
}

```
<br/>

- 堆排序： 利用神奇的堆的特性，进行原址排序，和归并排序一样，最坏时间复杂度（N Lg N）, 另外小根堆，大根堆在实现优先队列，求第 k 大问题上特别有用。 

```cpp
// 1. 定义维护堆性质的函数
// 2. 在数组基础上建堆，从下往上建(调用 1)。 
// 3. 通过依次交换堆中最后一个结点和堆的头结点，完成排序。 
```

<br/>

- 快速排序：  快速排序是一种最坏情况时间复杂度是 N^2 的排序算法。 虽然最坏情况时间复杂度很差，但是快速排序通常是实际排序应用种最好的选择，因为它的平均性能非常好： 它的期望时间复杂度是 N lg N。 而且 N lg N 中隐含的常数因子非常小，另外，它还能够进行原址排序，甚至在虚存环境中也能很好地工作。而且能有效利用缓冲区命中。 

```cpp
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

```

<br/>

#### 线性排序： 基于计算

- 计数排序， 假设 n 个输入元素中的每一个都是在 0 到 k 区间内的一个整数，其中 k 为某个整数。 当 k = O(n) 时，排序的运行时间为 O(n).   需要借助另外两个数组，B[]存放排序的输出， C[] 提供临时存储空间用于计数。 计数排序是稳定的。 在实际工作中，当 k = O(n)时，我们一般采用计数排序，这时的运行时间为O(n)。 

```cpp
// 计数排序
void num_sort(int data[], int begin, int end, int length)
{
    if(data == NULL || length <= 0 || begin < 0 || end >= length)
        throw runtime_error("Invalid Parameters");
    vector<int> count(100, 0);      // 假设排序的数字是 0 ~ 99 之间的整数 
    for(int i = begin; i <= end; i++)
        count[data[i]]++;
    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];
    vector<int> T(length, 0);
    for(int i = begin; i <= end; i++)
        T[i] = data[i];
    for(int i = begin; i <= end; i++)
    {
        data[count[T[i]]-1] = T[i];     // 排序数组从 0 开始，要减一
        count[T[i]]--;
    }
}

```

<br/>

- 基数排序：从最低有效位到最高有效位，分别进行计数排序。 时间复杂度 O(n)。 

```cpp
// 1.  把待排序数字，逻辑划分成若干有效位。 
// 2.  从最低位到最高位，依次进行 计数排序
```

<br/>

- 桶排序：假设输入数据服从均匀分布。桶排序假设输入数据是位于一个小区间内的均匀分布。桶排序把区间分为 n 个桶。 通过加权（同比例缩小）把数据用插入排序插入到相应的桶里。 然后把各个桶小到大拼接。 时间辅助度 O(n)，需要辅助链表。 

```cpp
// 1. 设计桶的规模，以及加权函数
// 2. 扫描数据，数据落入各个桶中时，进行插入排序
// 3. 合并各个桶
```

<br/>

### 额外补充： 
- 基数排序。 我们有时可以对具有多个关键字的记录进行排序，例如，我们希望用三个关键字（年，月和日）来对日期进行排序。我们当然可以用基于比较的排序算法：给定两个日期，先比较年，如果相同，再比较月，如果还是相同，就比较日。 但也可以用一种稳定排序算法（基数排序，计数排序）：先日，再月，再年。 

- 在处理 n 个关键字时，尽管基数排序执行的循环轮数会比快速排序要少，但每一轮它所耗费的时间要长的多。哪一个排序算法更合适依赖于具体实现和底层硬件的特性（例如，快速排序通常可以比基数排序更有效的利用硬件的缓存），以及输入数据的特征。此外，利用计数排序作为中间稳定排序的基数排序不是原址排序，而很多 O(N lg N)时间的比较排序是原址排序。 因此， 当主存的容量比较宝贵时，我们可能更倾向于像快速排序这样的原址排序。 

- 排序是稳定的： 具有相同值的元素在输出数组中的相对次序与它们在输入数组中的相对次序相同。 这个特征在当进行排序的数据具有卫星数据时也许很有用，而且基数排序的正确性依赖于计数排序（一般是它）的稳定性。 


#### 选择

- 最大值，最小值的选择都是 N 次比较
- 同时求最大值，最小值 需要 3n/2 次比较。 
- 用堆排序可以求第 k 小。 
- 利用快速排序里面的划分算法，在期望线性时间内，我们可以找到任一顺序统计量，特别是中位数。 
- 最坏情况为线性时间的选择算法： 把输入数组分为 n/5 组，用插入排序找每组中的中位数，按这种方式递归的寻找中位数。并用中位数进行划分（避免了划分不均的现象发生）。  

<br/>
**利用划分算法，实现线性选择**

```cpp
// 用划分算法找第 K 小
int Partition(int data[], int length, int start, int end);   // 划分函数

int Select_k(int data[], int length, int start, int end, int i)
{
	if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw runtime_error("Invalid Parameters");
    if(i<=0 || i > length)
    	throw runtime_error("Invalid Parameters");
	if(start == end)
		return data[start]; 
	int mid = Partition(data, length, start, end); 	// 调用划分函数
	int k = mid - start+1; 
	if(i == k)
		return A[mid]; 
	else if(i < k)
		return Select_k(data, length, start, mid-1, i);
	else 
		return Select_k(data, length, mid+1, end, i - k);  
}

int Swap(int& a, int& b);    // 交换函数
int Partition(int data[], int length, int start, int end)   // 划分函数
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw runtime_error("Invalid Parameters");
    // int index = RandomInRange(start, end);
    // swap(data[index], data[end]);
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
```
<br/>