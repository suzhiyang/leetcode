#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int i, j;
        vector<vector<int> > m;
        for (i = 0; i < grid.size(); ++i)
        {
            vector<int> r(grid[0].size());
            m.push_back(r);
        }
        m[0][0] = grid[0][0];
        for (i = 1; i < grid.size(); ++i)
            m[i][0] = grid[i][0] + m[i - 1][0];
        for (j = 1; j < grid[0].size(); ++j)
            m[0][j] = grid[0][j] + m[0][j - 1];

        for (i = 1; i < grid.size(); ++i)
        {
            for (j = 1; j < grid[0].size(); ++j)
            {
                if (m[i - 1][j] > m[i][j - 1]) m[i][j] = grid[i][j] + m[i][j - 1];
                else m[i][j] = grid[i][j] + m[i - 1][j];
            }
        }

        return m[grid.size() - 1][grid[0].size() - 1];
    }
};


int main()
{
    vector<vector<int> > grid;
//     int a[] = {1,2,3,4}, b[] = {8,7,6,5}, c[] = {9,10,11,12};
//     vector<int> v1(a, a + 4), v2(b, b + 4), v3(c, c + 4);
//     grid.push_back(v1);
//     grid.push_back(v2);
//     grid.push_back(v3);

    int a[] = {1,3,1}, b[] = {1,5,1}, c[] = {4,2,1};
    vector<int> v1(a, a + 3), v2(b, b + 3), v3(c, c + 3);
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);

    Solution s;
    cout<<s.minPathSum(grid)<<endl;
}
