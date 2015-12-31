#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char> > &board, int x, int y)
    {
        int i, j;
        for (i = 0; i < 9; ++i)
            if (i != x && board[i][y] == board[x][y]) return false;
        for (j = 0; j < 9; ++j)
            if (j != y && board[x][j] == board[x][y]) return false;
        for (i = x / 3 * 3; i < x / 3 * 3 + 3; ++i)
            for (j = y / 3 * 3; j < y / 3 * 3 + 3; ++j)
                if ((i != x || j != y) && board[i][j] == board[x][y]) return false;
        return true;
    }
    
    bool dfs(vector<vector<char> > &board)
    {
        int i, j, k;
        for (i = 0; i < 9; ++i)
        {
            for (j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (k = '1'; k <= '9'; ++k)
                    {
                        board[i][j] = char(k);
                        if (check(board, i, j) && dfs(board)) return true;
//                         if (!check(board, i, j)) continue;
//                         if (dfs(board)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char> >& board) {
        dfs(board);
    }
};

// class Solution {
// public:
//     bool check(vector<vector<char> > &board, int x, int y, char c)
//     {
//         int i, j;
//         for(i = 0; i < 9; ++i)
//             if ((board[x][i] == c && i != y) || (board[i][y] == c && i != x)) return false;
//         int sx = x / 3, sy = y / 3; // subbox (x,y)
//         for(i = sx * 3; i < sx * 3 + 3; ++i)
//             for(j = sy * 3; j < sy * 3 + 3; ++j)
//                 if (i != x && j != y && board[i][j] == c) return false;
//         return true;
//     }
    
//     bool dfs(vector<vector<char> > &board)
//     {
//         int i, j, k;
//         for (i = 0; i < 9; ++i)
//         {
//             for (j = 0; j < 9; ++j)
//             {
//                 if (board[i][j] == '.')
//                 {
//                     for (k = '1'; k <= '9'; ++k)
//                     {
//                         if (!check(board, i, j, k)) continue;
//                         board[i][j] = k;
//                         if (dfs(board)) return true;
//                     }
//                     board[i][j] = '.';
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
//     void solveSudoku(vector<vector<char> >& board) {
//         dfs(board);
//     }
// };

int main()
{
    char a[][10] = {"53..7....",
                    "6..195...",
                    ".98....6.",
                    "8...6...3",
                    "4..8.3..1",
                    "7...2...6",
                    ".6....28.",
                    "...419..5",
                    "....8..79"};
    vector<vector<char> > board(9, vector<char>(9, '.'));
    int i, j;
    for (i = 0; i < 9; ++i)
        board[i].assign(a[i], a[i] + 9);
    Solution s;
    s.solveSudoku(board);
    for (i = 0; i < 9; ++i)
    {
        for (j = 0; j < 9; ++j)
            cout<<board[i][j];
        cout<<endl;
    }
}
