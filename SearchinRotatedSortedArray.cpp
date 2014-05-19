#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (target == A[mid]) return mid;
            if (A[mid] >= A[left]) // [left, mid] is sorted
            {
                if (target < A[mid])
                {
                    if (target >= A[left]) right = mid - 1;
                    else left = mid + 1;
                }
                else left = mid + 1;
            }
            else // [mid, right] is sorted
            {
                if (target > A[mid])
                {
                    if (target <= A[right]) left = mid + 1;
                    else right = mid - 1;
                }
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    int b[] = {4, 5, 6, 7, 0, 1, 2, 10};
    for(int i = 0; i < sizeof(b) / 4; ++i)
    {
        cout<<b[i]<<":"<<s.search(a, 7, b[i])<<endl;
    }
}
