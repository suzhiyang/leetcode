class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int a = INT_MAX, b = INT_MAX, i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > b) return true;
            if (nums[i] <= a) a = nums[i];
            else if (nums[i] < b) b = nums[i];
        }
        return false;
    }
};
