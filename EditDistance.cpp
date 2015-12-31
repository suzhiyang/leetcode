class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), i, j;
        int **dp = new int*[m + 1];
        for (i = 0; i <= m; ++i)
        {
            dp[i] = new int[n + 1];
            memset(dp[i], 0, (n + 1) * sizeof(int));
        }
        for (i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (j = 0; j <= n; ++j)
            dp[0][j] = j;
        for (i = 1; i <= m; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};
