#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int> > sum;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size(), i, j;
        sum.resize(m); sum[0].resize(n);
        sum[0][0] = matrix[0][0];
        for (i = 1; i < m; ++i)
        {
            sum[i].resize(n);
            sum[i][0] = sum[i - 1][0] + matrix[i][0];
        }
        for (j = 1; j < n; ++j)
            sum[0][j] = sum[0][j - 1] + matrix[0][j];
        for (i = 1; i < m; ++i)
            for (j = 1; j < n; ++j)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = 0, b = 0, overlap = 0;
        if (row1 > 0) a = sum[row1 - 1][col2];
        if (col1 > 0) b = sum[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) overlap = sum[row1 - 1][col1 - 1];
        return sum[row2][col2] - a - b + overlap;
    }
};

int main()
{
    int a[][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    vector<vector<int> > matrix(5, vector<int>(5, 0));
    int i, j;
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            matrix[i][j] = a[i][j];
    NumMatrix numMatrix(matrix);
    cout<<numMatrix.sumRegion(2,1,4,3)<<endl;
}            
