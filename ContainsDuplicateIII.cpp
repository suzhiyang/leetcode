class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i;
        while(k > 0)
        {
            for (i = 0; i < nums.size() - k; ++i)
                if (fabs(nums[i] - nums[i + k]) <= t) return true;
            --k;
        }
        return false;
    }
};
