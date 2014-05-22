#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> r;
        if (matrix.size() == 0) return r;
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        int i, j;
        int r1 = 0, r2 = row, c1 = 0, c2 = col;
        while(r1 <= r2 && c1 <= c2)
        {
            for(j = c1; j <= c2; ++j)
                r.push_back(matrix[r1][j]);
            for(i = r1 + 1; i <= r2; ++i)
                r.push_back(matrix[i][c2]);
            if (r1 != r2)
            {
                for(j = c2 - 1; j >= c1; --j)
                    r.push_back(matrix[r2][j]);
            }
            if (c1 != c2)
            {
                for(i = r2 - 1; i >= r1 + 1; --i)
                    r.push_back(matrix[i][c1]);
            }
            ++c1; ++r1; --c2; --r2;
        }
        return r;
    }
};

int main()
{
//     int a[] = {1, 2, 3};
//     int b[] = {4, 5, 6};
//     int c[] = {7, 8, 9};
//     vector<vector<int> > m;
//     vector<int> t1(a, a + 3);
//     vector<int> t2(b, b + 3);
//     vector<int> t3(c, c + 3);
//     m.push_back(t1);
//     m.push_back(t2);
//     m.push_back(t3);
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int c[] = {9, 10, 11, 12};
    vector<vector<int> > m;
    vector<int> t1(a, a + 4);
    vector<int> t2(b, b + 4);
    vector<int> t3(c, c + 4);
    m.push_back(t1);
    m.push_back(t2);
    m.push_back(t3);
    Solution s;
    vector<int> r = s.spiralOrder(m);
    for(int i = 0; i < r.size(); ++i)
        cout<<r[i]<<" ";
    cout<<endl;
}
