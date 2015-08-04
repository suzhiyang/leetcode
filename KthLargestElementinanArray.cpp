#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void buildheap(vector<int> &a)
    {
        int i;
        for (i = a.size() / 2; i >= 0; --i)
            heapify(a, i, a.size());
    }

    void heapify(vector<int> &a, int s, int n)
    {
        int i, l = 2 * s + 1, r = 2 * s + 2, m = s, t;
        if (l < n && a[m] < a[l]) m = l;
        if (r < n && a[m] < a[r]) m = r;
        if (m != s)
        {
            swap(a[m], a[s]);
            heapify(a, m, n);
        }
    }
    
    int findKthLargest(vector<int> &nums, int k) {
        int i, t;
        buildheap(nums);
        for (i = 0; i < k; ++i)
        {
            heapify(nums, 0, nums.size() - i);
            swap(nums[0], nums[nums.size() - 1 - i]);
        }
        return nums[nums.size() - i];
    }
};

int main()
{
    int a[] = {3,2,1,5,6,4};
    vector<int> v(a, a + 4);
    Solution s;
    cout<<s.findKthLargest(v, 2)<<endl;
}
