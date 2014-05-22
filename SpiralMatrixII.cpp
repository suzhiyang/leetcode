#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > r(n, vector<int>(n, 0));
        if (n == 0) return r;
        int i, j;
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1, count = 0;
        while(r1 <= r2 && c1 <= c2)
        {
            for(j = c1; j <= c2; ++j)
                r[r1][j] = ++count;
            for(i = r1 + 1; i <= r2; ++i)
                r[i][c2] = ++count;
            if (r1 != r2)
            {
                for(j = c2 - 1; j >= c1; --j)
                    r[r2][j] = ++count;
            }
            if (c1 != c2)
            {
                for(i = r2 - 1; i >= r1 + 1; --i)
                    r[i][c1] = ++count;
            }
            ++c1; ++r1; --c2; --r2;
        }
        return r;
    }
};

int main()
{
    Solution s;
    int n = 4;
    vector<vector<int> > r = s.generateMatrix(n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
