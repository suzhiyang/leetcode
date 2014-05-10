#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int p = 0, q = n - 1, t, i = 0;
        while(i <= q)
        {
            if (A[i] == 0)
            {
                t = A[i];
                A[i] = A[p];
                A[p++] = t;
                ++i;
            }
            else if (A[i] == 2)
            {
                t = A[i];
                A[i] = A[q];
                A[q--] = t;
            }
            else ++i;
        }
    }
};

int main()
{
    Solution s;
    int i;
    int a[] = {0,1,0,1,2,1,0,1};
    s.sortColors(a, 8);
    for(i = 0; i < 8; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
