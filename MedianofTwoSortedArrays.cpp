#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int la = 0, ra = m - 1, lb = 0, rb = n - 1, ma, mb, med;
        int k = (m + n + 1) / 2;
        while(la <= ra || lb <= rb)
        {
            ma = (la + ra) / 2;
            mb = (lb + rb) / 2;
            if (A[ma] == B[mb]) break;
            if (ma + mb + 2 > k)
            {

            }
        }
        if ((m + n) % 2 != 0) return A[ma];
        else return 
    }
};

int main()
{
}
