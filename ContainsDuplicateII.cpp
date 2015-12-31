class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        unordered_set<int> h;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k) h.erase(nums[i - k - 1]);
            if (h.count(nums[i])) return true;
            h.insert(nums[i]);
        }
        return false;
    }
};
