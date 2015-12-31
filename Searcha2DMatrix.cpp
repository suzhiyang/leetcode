class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int l = 0, r = matrix.size() * matrix[0].size() - 1, mid, x, y;
        while (l <= r)
        {
            mid = (l + r) / 2;
            x = mid / matrix[0].size();
            y = mid - x * matrix[0].size();
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
