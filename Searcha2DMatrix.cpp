#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // 2 times binary search
        int maxrow, maxcol;
        maxrow = matrix.size() - 1;
        maxcol = matrix[0].size() - 1;
        if (target < matrix[0][0]) return false;
        int left, right, mid;
        left = 0; right = maxrow;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (target == matrix[mid][0]) return true;
            if (target < matrix[mid][0]) right = mid - 1;
            else left = mid + 1;
        }
        int rowindex = right; // IMPORTANT!
        left = 0; right = maxcol;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (target == matrix[rowindex][mid]) return true;
            if (target < matrix[rowindex][mid]) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

int main()
{
    int a[] = {1,   3,  5,  7};
    int b[] = {10, 11, 16, 20};
    int c[] = {23, 30, 34, 50};
    vector<vector<int> > m;
    vector<int> t1(a, a + 4);
    vector<int> t2(b, b + 4);
    vector<int> t3(c, c + 4);
    m.push_back(t1);
    m.push_back(t2);
    m.push_back(t3);
    Solution s;
    int t;
    t = 3;
    cout<<t<<":"<<s.searchMatrix(m, t)<<endl;
    t = 30;
    cout<<t<<":"<<s.searchMatrix(m, t)<<endl;
    t = 11;
    cout<<t<<":"<<s.searchMatrix(m, t)<<endl;
    t = 78;
    cout<<t<<":"<<s.searchMatrix(m, t)<<endl;
    return 0;
}
