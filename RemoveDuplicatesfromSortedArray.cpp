#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int count = 1, i;
        for(i = 1; i < n; ++i)
        {
            if (A[i] != A[count - 1])
                A[count++] = A[i];
        }
        return count;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 1, 2};
    int count, i;
    count = s.removeDuplicates(a, 3);
    for (i = 0; i < count; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
