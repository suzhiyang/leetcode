class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int **dp = new int*[m], i, j;
        for (i = 0; i < m; ++i)
            dp[i] = new int[n];
        dp[m - 1][n - 1] = max(1 - dungeon[m - 1][n - 1], 1);
        for (i = m - 2; i >= 0; --i)
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
        for (j = n - 2; j >= 0; --j)
            dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
        for (i = m - 2; i >= 0; --i)
            for (j = n - 2; j >= 0; --j)
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        return dp[0][0];
    }
};
