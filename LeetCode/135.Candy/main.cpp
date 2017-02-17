#include <iostream>
#include <vector>
using namespace std;
  int candy(vector<int> &ratings)
 {
	 int len=ratings.size();
	 if(len<=1)
		 return len;
	 vector<int> num(len,1);
	 for (int i = 1; i < len; i++)
	 {
		 if(ratings[i]>ratings[i-1])
			 num[i]=num[i-1]+1;
	 }
	 for (int i= len-1; i>0 ; i--)
	 {
		 if(ratings[i-1]>ratings[i])
			 num[i-1]=max(num[i]+1,num[i-1]);
	 }

	 int result=0;
	 for (int i = 0; i < len; i++)
		 result+=num[i];

	 // debug
	 // for (auto i : num)
     //   cout << num[i] << " ";

	 return result;
 }
int main()
{
    vector<int> ratings{5, 8, 10, 7, 6, 2, 5, 9, 8, 8, 7, 6, 5, 5, 6, 7, 7, 9};
    cout << candy(ratings) << endl;
    return 0;
}
