class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() < 2) return nums[0];
        int r = 0, *dp = new int[nums.size()], i;
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (i = 2; i < nums.size(); ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[nums.size() - 1];
    }
};
