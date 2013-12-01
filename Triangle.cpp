#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row, col;
        vector<vector<int> > sum;
        for (row = 0; row < triangle.size(); ++row)
        {
            int colsize = triangle[row].size();
            vector<int> sumrow(colsize);
            sum.push_back(sumrow);
            if (row > 0)
            {
                sum[row][0] = triangle[row][0] + sum[row - 1][0];
                sum[row][colsize - 1] = triangle[row][colsize - 1] + sum[row - 1][colsize - 2];
            }
            else sum[0][0] = triangle[0][0];
            for(col = 1; col < colsize - 1; ++col)
            {
                sum[row][col] = triangle[row][col];
                if (sum[row - 1][col - 1] < sum[row - 1][col])
                    sum[row][col] += sum[row - 1][col - 1];
                else
                    sum[row][col] += sum[row - 1][col];
            }
        }
        int min = 999999;
        row = sum.size() - 1;
        for (col = 0; col < sum[row].size(); ++col)
        {
            if (sum[row][col] < min) min = sum[row][col];
        }
        for (row = 0; row < sum.size(); ++row)
        {
            for(col = 0; col < sum[row].size(); ++col)
                cout<<sum[row][col]<<",";
            cout<<endl;
        }
        return min;
    }
};

int main()
{
    vector<vector<int> > triangle;
    int a1[] = {2};
    int a2[] = {3,4};
    int a3[] = {6,5,7};
    int a4[] = {4,1,8,3};
    vector<int> r1(a1, a1 + sizeof(a1) / sizeof(int));
    vector<int> r2(a2, a2 + sizeof(a2) / sizeof(int));
    vector<int> r3(a3, a3 + sizeof(a3) / sizeof(int));
    vector<int> r4(a4, a4 + sizeof(a4) / sizeof(int));
    triangle.push_back(r1);
    triangle.push_back(r2);
    triangle.push_back(r3);
    triangle.push_back(r4);

    Solution s;
    cout<<s.minimumTotal(triangle)<<endl;
    return 0;
}
