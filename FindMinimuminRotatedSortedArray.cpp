class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while(l < r - 1)
        {
            m = l + (r - l) / 2;
            if (nums[l] < nums[m] && nums[m] > nums[r])
                l = m + 1;
            else if (nums[l] > nums[m] && nums[m] < nums[r])
                r = m;
            else break;
        }
        return min(nums[l], nums[r]);
    }
};
