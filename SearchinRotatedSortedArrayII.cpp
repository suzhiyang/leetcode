class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while(l < r)
        {
            m = l + (r - l) / 2;
            if (target == nums[m]) return true;
            if (nums[m] < nums[r])
            {
                if (target > nums[m] && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
            else if (nums[m] > nums[r])
            {
                if (target >= nums[l] && target < nums[m]) r = m - 1;
                else l = m + 1;
            }
            else --r;
        }
        return false;
    }
};
