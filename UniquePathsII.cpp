#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int a[105][105];
        int i, j;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for(i = 0; i < m + 1; ++i)
            a[0][m] = 0;
        for(i = 0; i < n + 1; ++i)
            a[n][0] = 0;
        a[0][1] = 1;
        for(i = 1; i < m + 1; ++i)
        {
            for(j = 1; j < n + 1; ++j)
            {
                if (obstacleGrid[i - 1][j - 1] == 1) a[i][j] = 0;
                else a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m][n];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > o(3);
    o[0].push_back(0);
    o[0].push_back(0);
    o[0].push_back(0);
    
    o[1].push_back(0);
    o[1].push_back(1);
    o[1].push_back(0);
    
    o[2].push_back(0);
    o[2].push_back(0);
    o[2].push_back(0);
    cout<<s.uniquePathsWithObstacles(o)<<endl;
}
