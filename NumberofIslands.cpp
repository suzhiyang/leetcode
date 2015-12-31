class Solution {
public:
    void dfs(vector<vector<char> > &grid, vector<vector<int> > &v, int x, int y)
    {
        if (v[x][y] == 1 || grid[x][y] == '0') return;
        v[x][y] = 1;
        if (x - 1 >= 0) dfs(grid, v, x - 1, y);
        if (x + 1 < grid.size()) dfs(grid, v, x + 1, y);
        if (y - 1 >= 0) dfs(grid, v, x, y - 1);
        if (y + 1 < grid[0].size()) dfs(grid, v, x, y + 1);
    }

    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<int> > v(grid.size(), vector<int>(grid[0].size(), 0));
        int i, j, c = 0;
        for (i = 0; i < grid.size(); ++i)
        {
            for (j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1' && v[i][j] == 0)
                {
                    dfs(grid, v, i, j);
                    ++c;
                }
        }
        return c;
    }
};
