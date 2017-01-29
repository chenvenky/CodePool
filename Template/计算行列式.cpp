#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


int Merge_Sort(int * A, int x, int y)
{
	 int T[1000];
	int cnt = 0;
	if(y-x > 1) 
	{
		int m = x + (y-x)/2;
		int p = x, q = m, i = x;
		Merge_Sort(A, x, m);
		Merge_Sort(A, m, y);
		while(p < m || q < y)
		{
			if(q >= y ||(p<m && A[p] <= A[q])) T[i++] = A[p++];
			else  {	T[i++] = A[q++]; cnt += m-p;}
		} 	
	}
	return cnt; 		// 归并排序求出逆序数 
}			

template <typename TT>
void solve(int n,  TT a[15][15])
{
    int flag = 0; 
    TT ans=0;
    int p[15];
    for(int i=0; i<n; i++) 
    p[i] = i+1;
    cout << "\n    计算算式为:\t"; 
    do
    {
        int ok = Merge_Sort(p, 0, n); 
        if(ok&1) 
        {
            flag++;
           printf(" - ");
            TT temp=1;
            for(int j=1, i=0; i<n; j++, i++)
            {
                temp*= a[j][p[i]];
                if(j!=1)printf(" * ");
                cout << a[j][p[i]];
                
            }
            ans-=temp;
        }
        else 
        {
           if(flag)printf(" + ");
           flag++;
             TT temp=1;
            for(int j=1, i=0; i<n; j++, i++)
            {
                temp*=a[j][p[i]];
                if(j!=1)printf(" * ");
                cout<< a[j][p[i]]; 
            }
            ans+=temp;
        }
    }while(next_permutation(p, p+n));
    cout<<endl;
    cout <<"\n\n行列式的结果为: " <<ans << endl << endl; 
}

int main() 
{
  int n;
  double a[15][15];					// whatever types you want 
  cout<<"请输入所求行列式的阶数: ";
  while(scanf("%d", &n)!=EOF)
  {    
   	  cout << "\n请输入 "<<n<< " * " <<n<< " 的行列式！\n\n"; 
      for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
      cin >> a[i][j]; 
      solve(n, a);
      cout<<"请输入所求行列式的阶数: ";
  }
  return 0;
}