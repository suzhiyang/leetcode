int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

class Solution {
public:
    int count(vector<vector<int> > &board, int x, int y)
    {
        int r = 0, i, m = board.size(), n = board[0].size();
        for (i = 0; i < 8; ++i)
        {
            if (x + dx[i] >= 0 && x + dx[i] < m &&
                y + dy[i] >= 0 && y + dy[i] < n &&
                (board[x + dx[i]][y + dy[i]] & 1) == 1)
                ++r;
        }
        return r;
    }
    
    void gameOfLife(vector<vector<int> >& board) {
        int i, j, m = board.size(), n = board[0].size();
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                int c = count(board, i, j);
                if (board[i][j] == 1)
                {
                    if (c == 2 || c == 3) board[i][j] = 3;
                }
                else
                {
                    if (c == 3) board[i][j] = 2;
                }
            }
        }
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
                board[i][j] = board[i][j] >> 1;
        }
    }
};
