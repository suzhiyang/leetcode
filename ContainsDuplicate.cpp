class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> h;
        for (int i = 0; i < nums.size(); ++i)
            if (h.find(nums[i]) != h.end()) return true;
            else h.insert(nums[i]);
        return false;
    }
};
