#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (target == A[mid]) return true;
            if (A[mid] > A[left]) // [left, mid] is sorted
            {
                if (target < A[mid])
                {
                    if (target >= A[left]) right = mid - 1;
                    else left = mid + 1;
                }
                else left = mid + 1;
            }
            else if (A[mid] == A[left]) ++left;
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
        return false;
    }
};

int main()
{
    int a[] = {1,5,1,1,1,1,1,1,1,1};
    Solution s;
    int b[] = {1,2,5};
    for(int i = 0; i < sizeof(b) / 4; ++i)
    {
        cout<<b[i]<<":"<<s.search(a, 10, b[i])<<endl;
    }
}
