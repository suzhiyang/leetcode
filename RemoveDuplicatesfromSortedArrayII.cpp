#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int count = 1, i, dup = 1;
        for(i = 1; i < n; ++i)
        {
            if (A[i] == A[count - 1]) ++dup;
            else dup = 1;
            if (dup < 3) A[count++] = A[i];
        }
        return count;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 1, 1, 2, 2, 3};
    int count, i;
    count = s.removeDuplicates(a, 6);
    for (i = 0; i < count; ++i)
        cout<<a[i]<<" ";
    cout<<endl;

    int b[] = {1, 1, 1, 2, 2, 3, 3, 3};
    count = s.removeDuplicates(b, 7);
    for (i = 0; i < count; ++i)
        cout<<b[i]<<" ";
    cout<<endl;

}
