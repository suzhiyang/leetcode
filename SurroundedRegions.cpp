#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    void bfs(vector<vector<char> > &board, int x, int y)
    {
        queue<pair<int, int> > q;
        board[x][y] = 'V';
        q.push(make_pair(x, y));
        while(!q.empty())
        {
            pair<int, int> e = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int dx = e.first + dir[k][0], dy = e.second + dir[k][1];
                if (dx >= 0 && dx < board.size() && dy >= 0 && dy < board[0].size() &&
                    board[dx][dy] == 'O')
                {
                    board[dx][dy] = 'V';
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
    
    void solve(vector<vector<char> >& board) {
        if (board.size() <= 2) return;
        int m = board.size(), n = board[0].size(), i, j;
        for (i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n - 1] == 'O') bfs(board, i, n - 1);
        }
        for (j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m - 1][j] == 'O') bfs(board, m - 1, j);
        }
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'V') board[i][j] = 'O';
        }
    }
};
// class Solution {
// public:
//     void solve(vector<vector<char> >& board) {
//         if (board.size() <= 2) return;
//         int m = board.size(), n = board[0].size();
//         queue<pair<int, int> > q;
//         int i, j, k;
//         for (i = 1; i < m - 1; ++i)
//         {
//             for (j = 1; j < n - 1; ++j)
//             {
//                 if (board[i][j] == 'O')
//                 {
//                     bool flag = true;
//                     vector<pair<int, int> > v;
//                     q.push(make_pair(i, j));
//                     board[i][j] = 'V';
//                     while(!q.empty())
//                     {
//                         pair<int, int> pt = q.front();
//                         q.pop();
//                         v.push_back(pt);
//                         for (k = 0; k < 4; ++k)
//                         {
//                             int x = pt.first + dir[k][0], y = pt.second + dir[k][1];
//                             if (x > 0 && x < m - 1 && y > 0 && y < n - 1)
//                             {
//                                 if (board[x][y] == 'O')
//                                 {
//                                     board[x][y] = 'V';
//                                     q.push(make_pair(x, y));
//                                 }
//                             }
//                             else if (board[x][y] == 'O') flag = false;
//                         }
//                     }
//                     if (!flag)
//                         for (auto t : v)
//                         {
//                             board[t.first][t.second] = 'I';
//                         }
//                 }
//             }
//         }
//         // for (i = 0; i < m; ++i)
//         // {
//         //     for (j = 0; j < n; ++j)
//         //         cout<<board[i][j];
//         //     cout<<endl;
//         // }
//         for (i = 1; i < m - 1; ++i)
//         {
//             for (j = 1; j < n - 1; ++j)
//                 if (board[i][j] == 'V') board[i][j] = 'X';
//                 else if (board[i][j] == 'I') board[i][j] = 'O';
//         }
//     }
// };

// class Solution {
// public:
//     bool dfs(vector<vector<char> > &board, int x, int y)
//     {
//         if (board[x][y] == 'X') return true;
//         if (x == 0 || x == board.size() - 1 || y == 0 || y == board[0].size() - 1)
//             return false;
//         board[x][y] = 'V';
//         bool flag = true;
//         if (board[x + 1][y] == 'O') flag = flag && dfs(board, x + 1, y);
//         if (board[x - 1][y] == 'O') flag = flag && dfs(board, x - 1, y);
//         if (board[x][y + 1] == 'O') flag = flag && dfs(board, x, y + 1);
//         if (board[x][y - 1] == 'O') flag = flag && dfs(board, x, y - 1);
//         if (flag) board[x][y] = 'X';
//         return flag;
//     }
    
//     void solve(vector<vector<char> >& board) {
//         int i, j;
//         if (board.size() <= 2) return;
//         for (i = 0; i < board.size(); ++i)
//         {
//             for (j = 0; j < board[0].size(); ++j)
//                 if (board[i][j] == 'O' && dfs(board, i, j)) board[i][j] = 'X';
//         }
//         for (i = 0; i < board.size(); ++i)
//             for (j = 0; j < board[0].size(); ++j)
//                 if (board[i][j] == 'V') board[i][j] = 'O';
//     }
// };

int main()
{
    int i, j, n;
    n = 5;
    char a[][10] = {"OXXOX",
                    "XOOXO",
                    "XOXOX",
                    "OXOOO",
                    "XXOXO"};
    vector<vector<char> > v(n);
    for (i = 0; i < n; ++i)
        v[i].assign(a[i], a[i] + n);
    // char a[][10] = {"OOO", "OOO", "OOO"};
    // vector<vector<char> > v(3);
    // for (i = 0; i < 3; ++i)
    //     v[i].assign(a[i], a[i] + 3);
    Solution s;
    s.solve(v);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            cout<<v[i][j];
        cout<<endl;
    }
}
