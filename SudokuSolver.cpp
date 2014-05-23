#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

class CCell
{
public:
    int m_x, m_y;
    set<int> m_candidates;
    CCell(int x, int y) : m_x(x), m_y(y) {for(int i = 1; i <= 9; ++i) m_candidates.insert(i);}
    CCell(int x, int y, set<int> &c) : m_x(x), m_y(y), m_candidates(c) {}
};

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
    
    bool solve(vector<vector<char> > &board) {
        int a[] = {1,2,3,4,5,6,7,8,9};
        int bitset[10], left = 0;
        int i, j, k, t;
        char c;
        // Check blank grid number
        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for(k = 0; k < 9; ++k)
                    {
                        c = '1' + k;
                        board[i][j] = c;
                        if (check(board, i, j, c) && solve(board)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char> > &board, int x, int y, char c)
    {
        int i, j;
        for(i = 0; i < 9; ++i)
            if ((board[x][i] == c && i != y) || (board[i][y] == c && i != x)) return false;
        int sx = x / 3, sy = y / 3; // subbox (x,y)
        for(i = sx * 3; i < sx * 3 + 3; ++i)
            for(j = sy * 3; j < sy * 3 + 3; ++j)
                if (i != x && j != y && board[i][j] == c) return false;
        return true;
    }
};

int main()
{
    vector<vector<char> > board(9, vector<char>(9));
    char *a[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
        //{"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419...5", "....8..79"};
    int i, j;
    for(i = 0; i < 9; ++i)
        board[i].assign(a[i], a[i] + 9);
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    Solution s;
    s.solveSudoku(board);
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
