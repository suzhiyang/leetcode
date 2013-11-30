#include <iostream>

using namespace std;

/* 5 5 5 3
 * 0101 0101
 * 0101 0101
 * 0101 0101
 *      0011
 * ---------
 * 0303 0314
 */

#define N 40
class Solution {
public:
    void base2(int num, int *result)
    {
        int t = num;
        for (int i = 0; i < N; ++i)
        {
            result[i] = t % 2;
            t /= 2;
        }
    }
    
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int t[N] = {0}, s[N] = {0}, i, r, sign = 0;
        for (i = 0; i < n; ++i)
        {
            if (A[i] < 0)
            {
                A[i] = -A[i];
                ++sign;
            }
            base2(A[i], t);
            for (int j = 0; j < N; ++j)
                s[j] += t[j];
        }
        r = 0;
        for (i = N - 1; i >= 0; --i)
        {
            r = r * 2 + (s[i] % 3);
        }
        if (sign % 3 != 0) r = -r;
        return r;
    }
};

int main()
{
    int result[N];
    Solution s;
    s.base2(15, result);
    for (int i = 0; i < N; ++i)
    {
        cout<<result[i];
    }
    cout<<endl;

    int a[10] = {5,5,5,3,4,4,4,3,3,15};
    cout<<s.singleNumber(a, 10)<<endl;
    int b[4] = {5,5,5,-3};
    cout<<s.singleNumber(b, 4)<<endl;
    return 0;
}
