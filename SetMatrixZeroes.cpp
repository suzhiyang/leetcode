#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int i, j;
        int zero1line = 0, zero1col = 0;
        for(i = 0; i < matrix.size(); ++i)
            if (matrix[i][0] == 0) zero1col = 1;
        for(j = 0; j < matrix[0].size(); ++j)
            if (matrix[0][j] == 0) zero1line = 1;
        for(i = 0; i < matrix.size(); ++i)
        {
            for(j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                for(j = 0; j < matrix[i].size(); ++j)
                    matrix[i][j] = 0;
            }
        }
        for(j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[0][j] == 0)
            {
                for(i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
            }
        }
        if (zero1col == 1)
        {
            for(i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }
        if (zero1line == 1)
        {
            for(j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        }
    }
};

int main()
{
    vector<vector<int> > m(5, vector<int>(4));
    int a[][4] = {{0,0,0,5},
                 {4,3,1,4},
                 {0,1,1,4},
                 {1,2,1,3},
                 {0,0,1,1}};
    int i;
    for(i = 0; i < 5; ++i)
        m[i].assign(a[i], a[i] + 4);
    for(i = 0; i < 5; ++i)
    {
        for(int j = 0; j < m[i].size(); ++j)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    Solution s;
    s.setZeroes(m);
    for(i = 0; i < 5; ++i)
    {
        for(int j = 0; j < m[i].size(); ++j)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }

}
