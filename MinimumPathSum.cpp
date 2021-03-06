class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int i, j, m = grid.size(), n = grid[0].size();
        vector<int> dp(n, grid[0][0]);
        for (j = 1; j < n; ++j)
            dp[j] = dp[j - 1] + grid[0][j];
        for (i = 1; i < m; ++i)
        {
            dp[0] += grid[i][0];
            for (j = 1; j < n; ++j)
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
        return dp[n - 1];
    }
};
// class Solution {
// public:
//     int minPathSum(vector<vector<int> >& grid) {
//         int i, j, m = grid.size(), n = grid[0].size();
//         vector<vector<int> > dp(m, vector<int>(n, 0));
//         dp[0][0] = grid[0][0];
//         for (i = 1; i < m; ++i)
//             dp[i][0] = dp[i - 1][0] + grid[i][0];
//         for (j = 1; j < n; ++j)
//             dp[0][j] = dp[0][j - 1] + grid[0][j];
//         for (i = 1; i < m; ++i)
//             for (j = 1; j < n; ++j)
//                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//         return dp[m - 1][n - 1];
//     }
// };
