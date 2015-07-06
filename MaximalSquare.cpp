#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size(), i, j, m = 0;
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for (i = 0; i < row; ++i)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                m = 1;
            }
        }
        for (j = 0; j < col; ++j)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                m = 1;
            }
        }
        for (i = 1; i < row; ++i)
        {
            for (j = 1; j < col; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    ++dp[i][j];
                    m = max(m, dp[i][j]);
                }
            }
        }
        return m * m;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > m;
    char a[4][5] = {{'1','0','1','0','0'},
                    {'1','0','1','1','1'},
                    {'1','1','1','1','1'},
                    {'1','0','0','1','0'},
    };
    int i;
    for (i = 0; i < 4; ++i)
    {
        vector<char> v(a[i], a[i] + 5);
        m.push_back(v);
    }
    cout<<s.maximalSquare(m)<<endl;
}
