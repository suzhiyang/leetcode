class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while(l < r)
        {
            m = l + (r - l) / 2;
            if (nums[l] == nums[m] && nums[l] == nums[r]) return seqsearch(nums, l, r);
            else if (nums[l] < nums[m])
            {
                if (nums[m] <= nums[r]) r = m - 1;
                else l = m + 1;
            }
            else if (nums[l] > nums[m]) r = m;
            else if (nums[m] > nums[r]) l = m + 1; //else case: nums[l] == nums[m]
            else if (nums[m] < nums[r]) break;
        }
        return nums[l];
    }

    int seqsearch(vector<int> &nums, int l, int r)
    {
        int ret = nums[l], i;
        for (i = l + 1; i <= r; ++i)
            ret = min(ret, nums[i]);
        return ret;
    }
};
