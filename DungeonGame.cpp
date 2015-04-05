#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int> > m(row, vector<int>(col, 0));
        int i, j;
        m[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
        for (i = row - 2; i >= 0; --i)
            m[i][col - 1] = max(1, m[i + 1][col - 1] - dungeon[i][col - 1]);
        for (j = col - 2; j >= 0; --j)
            m[row - 1][j] = max(1, m[row - 1][j + 1] - dungeon[row - 1][j]);
        for (i = row - 2; i >= 0; --i)
            for (j = col - 2; j >= 0; --j)
                m[i][j] = max(1, min(m[i + 1][j], m[i][j + 1]) - dungeon[i][j]);
//         for(i = 0; i < row; ++i)
//         {
//             for(j = 0; j < col; ++j)
//                 cout<<m[i][j]<<",";
//             cout<<endl;
//         }
        return m[0][0];
    }
};

int main()
{
//     int a[][3] = {{-2, -3, 3},
//                   {-5, -10, 1},
//                   {10, 30, -5}};
//     int a[][3] = {{3, -20, 30},
//                   {-3, 4, 0}};
    int a[][3] = {{1, -3, 3},
                  {0, -2, 0},
                  {-3, -3, -3}};
    int i, j;
    vector<vector<int> > d;
    for (i = 0; i < 3; ++i)
        d.push_back(vector<int>(a[i], a[i] + 3));
    Solution s;
    cout<<s.calculateMinimumHP(d)<<endl;
}
