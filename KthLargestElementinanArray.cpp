#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findk(vector<int> &nums, int s, int e, int k)
    {
        if (s == e) return nums[s];
        int l = s, r = e - 1;
        while (l < r)
        {
            while(l < r && nums[l] <= nums[e]) ++l;
            while(l < r && nums[r] > nums[e]) --r;
            if (l < r) swap(nums[l], nums[r]);
        }
        if (nums[l] > nums[e]) swap(nums[l], nums[e]);
        else l = e;
        if (l == k) return nums[l];
        else if (l < k) return findk(nums, l + 1, e, k);
        else return findk(nums, s, l - 1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return findk(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main()
{
    int a[] = {3,1,2,4,5,6};
    vector<int> v;
    for (int i = 1; i <= 4; ++i)
    {
        v.assign(a, a + 4);
        cout<<Solution().findKthLargest(v, i)<<endl;
    }
}
