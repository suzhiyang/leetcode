class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        int i, r = 0, n = nums.size();
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (i = 2; i < n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        r = dp[n - 2];
        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        for (i = 2; i < n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return max(r, dp[n - 1]);
    }
};
