#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j, m = nums1.size(), n = nums2.size();
        if (m == 0 && n == 0) return 0;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        if (m == 0)
        {
            if (n % 2 == 0) return (nums2[(n - 1) / 2] + nums2[(n - 1) / 2 + 1]) / 2.0;
            else return nums2[(n - 1) / 2];
        }
        if (n == 0)
        {
            if (m % 2 == 0) return (nums1[(m - 1) / 2] + nums1[(m - 1) / 2 + 1]) / 2.0;
            else return nums1[(m - 1) / 2];
        }
        int l = 0, r = m, t1 = 0, t2 = 0;
        while(l <= r)
        {
            i = (l + r) / 2;
            j = (m + n + 1) / 2 - i;
            if (i > 0 && j < n && nums1[i - 1] > nums2[j]) r = i - 1;
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) l = i + 1;
            else break;
        }
        if (i == 0) t1 = nums2[j - 1];
        else if (j == 0) t1 = nums1[i - 1];
        else t1 = max(nums1[i - 1], nums2[j - 1]);
        if ((m + n) % 2 != 0) return t1;
        
        if (i == m) t2 = nums2[j];
        else if ( j == n) t2 = nums1[i];
        else t2 = min(nums1[i], nums2[j]);
        return (t1 + t2) / 2.0;
    }
};

int main()
{
    Solution s;
    int a[] = {1,2};
//    int a[] = {1};
    vector<int> s1(a, a + sizeof(a) / sizeof(int)), s2(a, a + sizeof(a) / sizeof(int));
    cout<<s.findMedianSortedArrays(s1, s2)<<endl;
}
