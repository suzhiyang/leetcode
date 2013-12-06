#include <iostream>

using namespace std;

class Solution {
public:
    // Merge the array from the tail of the two arrays
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pa = m - 1, pb = n - 1, pm = m + n - 1;
        while(pa >= 0 || pb >= 0)
        {
            if (pa < 0) A[pm] = B[pb--];
            else if (pb < 0) A[pm] = A[pa--];
            else
            {
                if (A[pa] > B[pb])
                    A[pm] = A[pa--];
                else
                    A[pm] = B[pb--];
            }
            --pm;
        }
    }
};

int main()
{
    Solution s;
    int a[] = {1,3,8,9}, b[] = {2,5,6,7,10};
    s.merge(a,4,b,5);
    int i;
    for (i = 0; i < 9; ++i)
        cout<<a[i]<<",";
    cout<<endl;
    
    return 0;
}
