class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int i, j, c = 1;
        int l = 0, r = n - 1, t = 0, b = n - 1;
        vector<vector<int> > m(n, vector<int>(n, 0));
        while(c <= n * n)
        {
            for (j = l; j <= r; ++j)
                m[t][j] = c++;
            for (i = t + 1; i <= b; ++i)
                m[i][r] = c++;
            if (t < b)
            {
                for (j = r - 1; j >= l; --j)
                    m[b][j] = c++;
            }
            if (l < r)
            {
                for (i = b - 1; i > t; --i)
                    m[i][l] = c++;
            }
            ++l; --r; ++t; --b;
        }
        return m;
    }
};
