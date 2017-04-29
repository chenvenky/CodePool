// 归并排序求逆序数

#### 分治三步法：

- **划分问题**: 把序列分成元素个数尽量相等的两半。 
- **递归求解**：把两半元素分别排序。
- **合并问题**：把两个有序表合并成一个。

// 归并排序

```cpp
void merge_sort(int data[], int start, int end, int T[])
{
	if(y - x > 1)
	{
		int mid = start + (end - start)/2; 		// 划分
		int pos1 = start, pos2 = mid, pos = start; 
		merge_sort(data[], start, mid, T); 		// 递归求解
		merge_sort(data[], mid, end, T); 		// 递归求解
		while(pos1 < mid || pos2 < mid)
		{
			if(pos2 >= mid || (pos1 < mid) && data[pos1] < data[pos2])
				T[pos++] = data[pos1++]; 
			else
				T[pos++] = data[pos2++]; 
		}
		for(pos = start; pos < end; pos++)
			data[pos] = T[pos]; 
	}
}
```

<br/>

// 归并排序求逆序数

```cpp
int cnt = 0; 
void merge_sort(int data[], int start, int end, int T[])
{
	if(end - start > 1)
	{
		int mid = start + (end - start)/2;	// 划分 
		int pos1 = start, pos2 = mid, pos = start; 
		merge_sort(data[], begin, mid, T); 
		merge_sort(data[], mid, end, T); 
		while(pos1 < mid || pos2 < end)
		{	
			if(pos2 >= end || (pos1 < mid && data[pos1] < data[pos2]))
				T[pos++] = data[pos1++]; 
			else
			{
				T[pos++] = data[pos2++]; 
				cnt += mid - pos1;		// 统计逆序数 
			}
		}
		for(pos = start; pos < end; pos++)
			data[pos] = T[pos]; 
	}
}
```

