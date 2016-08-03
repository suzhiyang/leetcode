#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int> > &matrix, vector<vector<int> > &p, int x, int y)
    {
        int m = matrix.size(), n = matrix[0].size(), i;
        if (p[x][y] > 1) return p[x][y];
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int l = 0;
        for (i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny <n && matrix[nx][ny] > matrix[x][y])
                l = max(l, dfs(matrix, p, nx, ny));
        }
        if (l > 0) p[x][y] = l + 1;
        return p[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), i, j, ml = 0;
        vector<vector<int> > p(m, vector<int>(n, 1));
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ml = max(ml, dfs(matrix, p, i, j));
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
                cout<<p[i][j]<<" ";
            cout<<endl;
        } 
        return ml;
    }
};

int main()
{
    vector<vector<int> > m;
    int a[][5] = {{9,9,4},
                  {6,6,8},
                  {2,1,1}};
    vector<int> v;
    for (int i = 0; i < 3; ++i)
    {
        v.assign(a[i], a[i] + 3);
        m.push_back(v);
    }
    cout<<Solution().longestIncreasingPath(m)<<endl;
}
