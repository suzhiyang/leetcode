class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows == 0) return vector<vector<int> >();
        vector<vector<int> > r(1, vector<int>(1, 1));
        int i, j;
        for (i = 1; i < numRows; ++i)
        {
            vector<int> row(1, 1);
            for (j = 1; j < i; ++j)
                row.push_back(r[i - 1][j - 1] + r[i - 1][j]);
            row.push_back(1);
            r.push_back(row);
        }
        return r;
    }
};
