#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> b(n, 0);
        b[0] = A[0];
        int i, max;
        for(i = 1; i < n; ++i)
        {
            if (b[i - 1] > 0) b[i] = b[i - 1] + A[i];
            else b[i] = A[i];
        }
        max = b[0];
        for(i = 1; i < n; ++i)
            if (b[i] > max) max = b[i];
        return max;
    }
};

int main()
{
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(a, sizeof(a) / sizeof(a[0]))<<endl;
}
