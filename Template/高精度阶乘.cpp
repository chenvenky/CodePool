/*********************************************
 n!   的API接口：
 传入参数: n
 返回结果（字符串）

**********************************************/

const int SIZE = 100; 
string ans;

void JieCheng(int n, string &ans)
{
	int a[SIZE];
	char ch[SIZE];
 	memset(a, 0, sizeof(a));
	a[0] = 1; 
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<SIZE; j++)
		a[j] *= i;
		for(int j=0; j<SIZE-1; j++)
		{
			a[j+1] += a[j]/10;
			a[j] %= 10;
		}
	}
	int flag = SIZE-1;
	while(!a[flag]) flag--;
	
	int j=0;
	for(int i=flag; i>=0; i--)
	ch[j++] = a[i]+'0';
	ch[j] = '\0';
    ans = ch;
}
