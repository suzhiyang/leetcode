#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int c;
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
    
    void fill(vector<string> &cur, int x)
    {
        int i;
        for (i = 0; i < cur.size(); ++i)
        {
            if (check(cur, x, i))
            {
                cur[x][i] = 'Q';
                if (x == cur.size() - 1) ++c;
                else fill(cur, x + 1);
                cur[x][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        c = 0;
        vector<string> cur(n, string(n, '.'));
        fill(cur, 0);
        return c;
    };
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; ++i)
        cout<<i<<" "<<s.totalNQueens(i)<<endl;
}
