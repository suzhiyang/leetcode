#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        int m = -INT_MAX, zeroindex = -1, t, i;
        for(i = 0; i < n; ++i)
        {
            if (A[i] == 0)
            {
                t = maxproductwithoutzero(&A[zeroindex + 1], i - zeroindex - 1);
                if (t > m) m = t;
                zeroindex = i;
            }
        }
        if (zeroindex == -1) return maxproductwithoutzero(A, n);
        else
        {
            t = maxproductwithoutzero(&A[zeroindex + 1], i - zeroindex - 1);
            if (t > m) m = t;
            if (m < 0) m = 0;
            return m;
        }
    }
    
    int maxproductwithoutzero(int A[], int n) {
        if (n == 0) return 0;
        if (n == 1) return A[0];
        int result = 1, i, firstindex = -1, lastindex = -1, minusnum = 0;
        for (i = 0; i < n; ++i)
        {
            result *= A[i];
            if (A[i] < 0)
            {
                ++minusnum;
                lastindex = i;
                if (firstindex == -1) firstindex = i;
            }
        }
        if (minusnum % 2 == 0) return result;
        int d1 = 1, d2 = 1;
        for (i = 0; i <= firstindex; ++i)
            d1 *= A[i];
        for (i = lastindex; i < n; ++i)
            d2 *= A[i];
        if (d1 > d2) return result / d1;
        else return result / d2;
    }
};

int main()
{
//    int A[] = {2,3,-2,4};
//    int A[] = {-5};
//    int A[] = {-5, 0, 2};
//    int A[] = {0, -5, 2, -2};
//    int A[] = {-2, 0, -2};
    int A[] = {0, -2, 0};
    Solution s;
    cout<<s.maxProduct(A, sizeof(A) / sizeof(A[0]))<<endl;
}
