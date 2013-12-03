#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) return result;
        vector<int> r1(1, 1);
        result.push_back(r1);
        int row, col;
        for (row = 1; row < numRows; ++row)
        {
            vector<int> ri;
            ri.push_back(1);
            for (col = 1; col < row; ++col)
            {
                ri.push_back(result[row - 1][col - 1] + result[row - 1][col]);
            }
            ri.push_back(1);
            result.push_back(ri);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > triangle = s.generate(5);
    int row, col;
    for (row = 0; row < triangle.size(); ++row)
    {
        for (col = 0; col < triangle[row].size(); ++col)
            cout<<triangle[row][col]<<",";
        cout<<endl;
    }
    return 0;
}
