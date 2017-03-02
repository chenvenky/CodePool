#include <iostream>
using namespace std;

class Solution{
public:
    int maxProduct(int A[], int n){
        int frontProduct = 1;
        int backProduct = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i){
            frontProduct *= A[i];
            backProduct *= A[n - i - 1];
            ans = max(ans, max(frontProduct, backProduct));
            frontProduct = frontProduct == 0 ? 1 : frontProduct;
            backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
} ;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

