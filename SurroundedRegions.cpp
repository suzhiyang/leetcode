#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
void printmatrix(vector<vector<T> > &m)
{
    int i, j;
    for(i = 0; i < m.size(); ++i)
    {
        for(j = 0; j < m[0].size(); ++j)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() < 1) return;
        int i, j;
        int row = board.size(), col = board[0].size();
        // Obtain the region starts from edge grid: not satisfied
        for(i = 0; i < row; ++i)
        {
            bfs(board, i, 0);
            bfs(board, i, col - 1);
        }
        for(j = 0; j < col; ++j)
        {
            bfs(board, 0, j);
            bfs(board, row - 1, j);
        }
        // Obtain the surrounded region: m_board[x][y] == 'O'
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'v') board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char> > &m, int x, int y)
    {
        if (m[x][y] != 'O') return;
        int row = m.size(), col = m[0].size();
        queue<int> q;
        q.push(x * col + y);
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            int cx = t / col, cy = t % col;
            m[cx][cy] = 'v';
            if (cx + 1 < row && m[cx + 1][cy] == 'O')
            {
                m[cx + 1][cy] = 'v';
                q.push((cx + 1) * col + cy);
            }
            if (cx - 1 >= 0 && m[cx - 1][cy] == 'O')
            {
                m[cx - 1][cy] = 'v';
                q.push((cx - 1) * col + cy);
            }
            if (cy + 1 < col && m[cx][cy + 1] == 'O')
            {
                m[cx][cy + 1] = 'v';
                q.push(cx * col + cy + 1);
            }
            if (cy - 1 >= 0 && m[cx][cy - 1] == 'O')
            {
                m[cx][cy - 1] = 'v';
                q.push(cx * col + cy - 1);
            }
        }
    }
};

// ******** DFS IMPLEMENTATION
// class Solution {
// private:
//     vector<vector<char> > m_board;
// public:
//     void solve(vector<vector<char> > &board) {
//         if (board.size() < 1) return;
//         m_board = board;
//         int i, j;
//         int row = board.size(), col = board[0].size();
//         // Obtain the region starts from edge grid: not satisfied
//         for(i = 0; i < row; ++i)
//         {
//             dfs(i, 0);
//             dfs(i, col - 1);
//         }
//         for(j = 0; j < col; ++j)
//         {
//             dfs(0, j);
//             dfs(row - 1, j);
//         }
//         // Obtain the surrounded region: m_board[x][y] == 'O'
//         for(i = 0; i < row; ++i)
//         {
//             for(j = 0; j < col; ++j)
//             {
//                 if (m_board[i][j] == 'O') board[i][j] = 'X';
//                 else if (m_board[i][j] == 'd') board[i][j] = 'O';
//             }
//         }
//     }

//     void dfs(int x, int y)
//     {
//         if (m_board[x][y] == 'X' || m_board[x][y] == 'd') return;
//         int row = m_board.size(), col = m_board[0].size();
//         m_board[x][y] = 'd';
//         if (x + 1 < row) dfs(x + 1, y);
//         if (x - 1 >= 0) dfs(x - 1, y);
//         if (y + 1 < col) dfs(x, y + 1);
//         if (y - 1 >= 0) dfs(x, y - 1);
//     }
// };

int main()
{
    char *a[20] = {"XXXXXXXXXXXXXXXXXXXX",
                   "XOOXOOOOOOOOOOOOXXXX",
                   "XXOXOXOXOXOXXXXXOOOO",
                   "OOXXXXXOXXXXXXXXXXOO"};
//     char *a[20] = 
//     {"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"
//    };
    vector<vector<char> > board(4, vector<char>(20));
    int i, j;
    Solution s;
    for(i = 0; i < board.size(); ++i)
    {
        board[i].assign(a[i], a[i] + board[0].size());
    }
    printmatrix(board);
    s.solve(board);
    printmatrix(board);
}
