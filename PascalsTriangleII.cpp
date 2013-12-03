#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ri;
        ri.push_back(1);
        if (rowIndex == 0) return ri;
        int row, col, t1, t2;
        for (row = 0; row < rowIndex; ++row)
        {
            t1 = 1;
            for (col = 1; col < row + 2; ++col)
            {
                t2 = t1;
                t1 = ri[col] + ri[col - 1];
                ri[col - 1] = t2;
            }
            ri.push_back(1);
        }
        return ri;
    }
};

int main()
{
    Solution s;
    int i, col;
    for (i = 0; i < 7; ++i)
    {
        vector<int> row = s.getRow(i);
        for (col = 0; col < row.size(); ++col)
            cout<<row[col]<<",";
        cout<<endl;
    }
    return 0;
}
