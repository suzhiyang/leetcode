#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m_islands;
    void dfs(vector<vector<char> > &grid, vector<vector<int> > &v, int x, int y, int tag)
    {
        if (v[x][y] > 0 || grid[x][y] == '0') return;
        v[x][y] = tag;
        if (x + 1 < grid.size()) dfs(grid, v, x + 1, y, tag);
        if (x - 1 >= 0) dfs(grid, v, x - 1, y, tag);
        if (y + 1 < grid[0].size()) dfs(grid, v, x, y + 1, tag);
        if (y - 1 >= 0) dfs(grid, v, x, y - 1, tag);
    }
    
    int numIslands(vector<vector<char> > &grid) {
        m_islands = 0;
        if (grid.size() == 0) return 0;
        vector<vector<int> > v(grid.size(), vector<int>(grid[0].size(), 0));
        int i, j;
        for (i = 0; i < grid.size(); ++i)
        {
            for (j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1' && v[i][j] == 0)
                    dfs(grid, v, i, j, ++m_islands);
        }
        return m_islands;
    }
};

int main()
{
}
