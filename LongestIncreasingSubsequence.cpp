class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int i, j, r = 1;
        for (i = 1; i < nums.size(); ++i)
            for (j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    r = max(r, dp[i]);
                }
        return r;
    }
};
