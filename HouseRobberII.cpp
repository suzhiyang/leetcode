class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int i, d1 = nums[0], d2 = max(nums[0], nums[1]), t, m;
        for (i = 2; i < nums.size(); ++i)
        {
            t = d2;
            d2 = max(d1 + nums[i], d2);
            d1 = t;
        }
        m = d2;
        d1 = 0; d2 = nums[1];
        for (i = 2; i < nums.size() - 1; ++i)
        {
            t = d2;
            d2 = max(d1 + nums[i], d2);
            d1 = t;
        }
        return max(d2, m);
    }
};
