class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if (matrix.size() == 0) return;
        int fr = 1, fc = 1, i, j, row = matrix.size(), col = matrix[0].size();
        if (matrix[0][0] == 0) fr = 0, fc = 0;
        for (i = 1; i < row; ++i)
            if (matrix[i][0] == 0) fc = 0;
        for (j = 1; j < col; ++j)
            if (matrix[0][j] == 0) fr = 0;
        for (i = 1; i < row; ++i)
        {
            for (j = 1; j < col; ++j)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (i = 1; i < row; ++i)
            if (matrix[i][0] == 0)
                for (j = 1; j < col; ++j) matrix[i][j] = 0;
        for (j = 1; j < col; ++j)
            if (matrix[0][j] == 0)
                for (i = 1; i < row; ++i) matrix[i][j] = 0;
        if (fc == 0)
            for (i = 0; i < row; ++i)
                matrix[i][0] = 0;
        if (fr == 0)
            for (j = 0; j < col; ++j)
                matrix[0][j] = 0;
    }
};
