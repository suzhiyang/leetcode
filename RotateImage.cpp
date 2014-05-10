#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int t, i, j;
        // Transposition first
        int n = matrix.size();
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < i; ++j)
            {
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        // Swap columns
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n / 2; ++j)
            {
                t = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = t;
            }
        }
    }
};

void printmatrix(vector<vector<int> > &matrix)
{
    int i, j;
    for(i = 0; i < matrix.size(); ++i)
    {
        for(j = 0; j < matrix[0].size(); ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Solution s;
//     int r1[] = {1,2,3};
//     int r2[] = {4,5,6};
//     int r3[] = {7,8,9};
//     vector<int> v1(r1, r1 + 3);
//     vector<int> v2(r2, r2 + 3);
//     vector<int> v3(r3, r3 + 3);
//     vector<vector<int> > m;
//     m.push_back(v1);
//     m.push_back(v2);
//     m.push_back(v3);

    int r1[] = {1,2,3,4};
    int r2[] = {5,6,7,8};
    int r3[] = {9,10,11,12};
    int r4[] = {13,14,15,16};
    vector<int> v1(r1, r1 + 4);
    vector<int> v2(r2, r2 + 4);
    vector<int> v3(r3, r3 + 4);
    vector<int> v4(r4, r4 + 4);
    vector<vector<int> > m;
    m.push_back(v1);
    m.push_back(v2);
    m.push_back(v3);
    m.push_back(v4);
    
    printmatrix(m);
    s.rotate(m);
    printmatrix(m);
}
