class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;
        int i, j, l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        while(l <= r && t <= b)
        {
            for (j = l; j <= r; ++j)
                ret.push_back(matrix[t][j]);
            for (i = t + 1; i <= b; ++i)
                ret.push_back(matrix[i][r]);
            if (t < b)
                for (j = r - 1; j >= l; --j)
                    ret.push_back(matrix[b][j]);
            if (l < r)
                for (i = b - 1; i > t; --i)
                    ret.push_back(matrix[i][l]);
            ++l; --r; ++t; --b;
        }
        return ret;
    }
};
