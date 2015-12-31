class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int h[10], i, j, m, n;
        for (i = 0; i < 9; ++i)
        {
            memset(h, 0, sizeof(h));
            for (j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                {
                    if (h[board[i][j] - '0'] == 1) return false;
                    else h[board[i][j] - '0'] = 1;
                }
        }
        for (j = 0; j < 9; ++j)
        {
            memset(h, 0, sizeof(h));
            for (i = 0; i < 9; ++i)
                if (board[i][j] != '.')
                {
                    if (h[board[i][j] - '0'] == 1) return false;
                    else h[board[i][j] - '0'] = 1;
                }
        }
        for (m = 0; m < 3; ++m)
        {
            for (n = 0; n < 3; ++n)
            {
                memset(h, 0, sizeof(h));
                for (i = 3 * m; i < 3 * m + 3; ++i)
                {
                    for (j = 3 * n; j < 3 * n + 3; ++j)
                        if (board[i][j] != '.')
                        {
                            if (h[board[i][j] - '0'] == 1) return false;
                            else h[board[i][j] - '0'] = 1;
                        }
                }
            }
        }
        return true;
    }
};
