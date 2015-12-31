class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size(), i, j;
        for (i = 0, j = col - 1; i < row && j >= 0;)
        {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) ++i;
            else --j;
        }
        return false;
    }
};
