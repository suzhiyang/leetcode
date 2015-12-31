class Solution {
public:
    int numTrees(int n) {
        int dp[1000] = {0}, i, j;
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (i = 3; i <= n; ++i)
        {
            for (j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
