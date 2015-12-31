class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        set<int> h;
        int i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (i > k) h.erase(nums[i - k - 1]);
            auto it = h.lower_bound(nums[i] - t);
            if (it != h.end() && *it - nums[i] <= t) return true;
            h.insert(nums[i]);
        }
        return false;
    }
};
