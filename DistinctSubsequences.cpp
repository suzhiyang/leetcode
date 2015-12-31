class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        int **dp = new int*[m + 1], i, j;
        for (i = 0; i <= m; ++i)
        {
            dp[i] = new int[n + 1];
            memset(dp[i], 0, (n + 1) * sizeof(int));
        }
        dp[0][0] = 1;
        for (i = 1; i <= m; ++i)
        {
            dp[i][0] = i;
            for (j = 1; j <= n; ++j)
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else dp[i][j] = dp[i - 1][j];
        }
        return dp[m][n];
    }
};
