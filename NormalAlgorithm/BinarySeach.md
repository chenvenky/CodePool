// 二分查找

```cpp
// 二分查找的迭代实现
int bsearch(int data[], int start, int end, int val)	// end 为未后元素
{
	int mid; 
	while(start < end)
	{
		mid = start + (end - start)/2; 
		if(data[mid] == val)
			return mid; 
		else if(data[mid] > val)
			end = m; 
		else 
			start = m + 1; 
	}
	return -1;	// 没找到
}

```
<br/>
// 二分下界查找
```cpp
int lower_bound(int data[], int start, int end, int val)
{
	int mid; 
	while(start < end)
	{
		mid = start + (end - start)/2; 
		if(data[mid] >= val)
			end = mid; 
		else 
			start = mid + 1; 
	}
	return start; 
}

```

// 二分下界查找

```cpp
int upper_bound(int data[], int start, int end, int val)
{
	int mid; 
	while(start < end)
	{
		mid = start + (end - start)/2; 
		if(data[mid <= val])
			start = mid+1; 
		else
			end = mid; 
	}
	return start; 
}
```