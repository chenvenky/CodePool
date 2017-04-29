// 快速幂

```cpp
// 非递归写法
int fastPow(int base, int num)
{
	if(num < 0)
		throw runtime_error("Invalid Input\n"); 
	else if(num == 0)
		return 1; 
	int res = 1; 
	while(num)
	{
		if(num & 1)
			res *= base; 
		base *= base; 
		num >>= 1; 
	}
	return res; 
}
```
<br/>

```cpp
// 递归写法
int fastPow(int base, int num)
{
	if(num < 0)
		throw runtime_error("Invalid Input\n"); 
	else if(num == 0)
		return 1; 

	if(num & 1)
		return base * fastPow(base * base, num >> 1); 
	else
		return fastPow(base * base, num >> 1); 
}
```
<br/>