class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        int i, j, m = matrix.size(), n = matrix[0].size(), r = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (i = 0; i < m; ++i)
        {
            dp[i][0] = matrix[i][0] - '0';
            r = max(r, dp[i][0]);
        }
        for (j = 0; j < n; ++j)
        {
            dp[0][j] = matrix[0][j] - '0';
            r = max(r, dp[0][j]);
        }
        for (i = 1; i < m; ++i)
        {
            for (j = 1; j < n; ++j)
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    r = max(r, dp[i][j]);
                }
        }
        return r * r;
    }
};
