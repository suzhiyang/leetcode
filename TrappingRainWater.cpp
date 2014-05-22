#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> v(n, 0);
        int i, cmax = A[0];
        for(i = 0; i < n; ++i)
        {
            if (A[i] > cmax) cmax = A[i];
            v[i] = cmax;
        }
        cmax = A[n - 1];
        for(i = n - 1; i >= 0; --i)
        {
            if (A[i] > cmax) cmax = A[i];
            if (cmax < v[i]) v[i] = cmax;
        }
        int r = 0;
        for(i = 0; i < n; ++i)
            r += v[i] - A[i];
//         for(i = 0; i < n; ++i)
//             cout<<A[i]<<" ";
//         cout<<endl;
//         for(i = 0; i < n; ++i)
//             cout<<v[i]<<" ";
//         cout<<endl;
        return r;
    }
};

int main()
{
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(a, sizeof(a) / sizeof(a[0]))<<endl;
}
