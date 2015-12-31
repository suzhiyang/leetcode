class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        if (matrix.size() == 0) return;
        int l = 0, r = matrix.size() - 1, i, t;
        while(l < r)
        {
            for (i = l; i < r; ++i)
            {
                t = matrix[l][i];
                matrix[l][i] = matrix[r - (i - l)][l];
                matrix[r - (i - l)][l] = matrix[r][r - (i - l)];
                matrix[r][r - (i - l)] = matrix[i][r];
                matrix[i][r] = t;
            }
            ++l; --r;
        }
    }
};
