#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 1) return 0;
        int mid, left = 0, right = num.size() - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (mid == 0)
            {
                if (num[mid] > num[mid + 1]) return 0;
                else left = mid + 1;
            }
            else if (mid == num.size() - 1)
            {
                if (num[mid] > num[mid - 1]) return mid;
                else right = mid - 1;
            }
            else
            {
                if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) return mid;
                if (num[mid - 1] > num[mid]) right = mid - 1;
                else if (num[mid + 1] > num[mid]) left = mid + 1;
            }
        }
    }
};

int main()
{
    Solution s;
//    int a[] = {1, 2, 3, 1};
//    int a[] = {10, 9, 8};
//    int a[] = {2, 3};
    int a[] = {1,2,1,2,3,1};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    cout<<s.findPeakElement(v)<<endl;
}
