class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int i, j, m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (i = 1; i < m; ++i)
            if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
        for (j = 1; j < n; ++j)
            if (obstacleGrid[0][j] == 1) dp[0][j] = 0;
            else dp[0][j] = dp[0][j - 1];
        for (i = 1; i < m; ++i)
        {
            for (j = 1; j < n; ++j)
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n - 1];
    }
};
