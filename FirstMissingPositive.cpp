#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i, t;
        for(i = 0; i < n; ++i)
        {
            if (A[i] > n || A[i] < 1) continue;
            while(A[i] != A[A[i] - 1])
            {
                t = A[i];
                A[i] = A[A[i] - 1];
                A[t - 1] = t;
                if (A[i] > n || A[i] < 1) break;
            }
        }
        for(i = 0; i < n; ++i)
        {
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main()
{
    Solution s;
    int a[] = {1,2,0};
    cout<<s.firstMissingPositive(a, 3)<<endl;
    int b[] = {3,4,-1,1};
    cout<<s.firstMissingPositive(b, 4)<<endl;
    int c[] = {3,4,2,5,1};
    cout<<s.firstMissingPositive(c, 5)<<endl;
    int d[] = {3,6,2,1,-1};
    cout<<s.firstMissingPositive(d, 5)<<endl;
    int e[] = {1,1};
    cout<<s.firstMissingPositive(e, 2)<<endl;
}
