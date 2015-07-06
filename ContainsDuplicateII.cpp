class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> h;
        int i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (h.find(nums[i]) != h.end()) return true;
            h.insert(nums[i]);
            if (i >= k) h.erase(nums[i - k]);
        }
        return false;
    }
};
