#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool check(vector<string> &cur, int x, int y)
    {
        int i, j;
        for (i = 0; i < cur.size(); ++i)
            if (i != x && cur[i][y] == 'Q') return false;
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
            if (cur[i][j] == 'Q') return false;
        for (i = x - 1, j = y + 1; i >= 0 && j < cur.size(); --i, ++j)
            if (cur[i][j] == 'Q') return false;
        for (i = x + 1, j = y - 1; i < cur.size() && j >= 0; ++i, --j)
            if (cur[i][j] == 'Q') return false;
        for (i = x + 1, j = y + 1; i < cur.size() && j < cur.size(); ++i, ++j)
            if (cur[i][j] == 'Q') return false;
        return true;
    }
    
    void fill(vector<vector<string> > &r, vector<string> &cur, int x)
    {
        int i;
        for (i = 0; i < cur.size(); ++i)
        {
            if (check(cur, x, i))
            {
                cur[x][i] = 'Q';
                if (x == cur.size() - 1) r.push_back(cur);
                else fill(r, cur, x + 1);
                cur[x][i] = '.';
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > r;
        vector<string> cur(n, string(n, '.'));
        fill(r, cur, 0);
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > r = s.solveNQueens(5);
    for (int i = 0; i < r.size(); ++i)
    {
        for (int j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<endl;
        cout<<endl;
    }
}
