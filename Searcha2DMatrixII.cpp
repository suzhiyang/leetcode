#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchline(vector<int> &v, int l, int r, int target)
    {
        int m;
        while(l <= r)
        {
            m = (l + r) / 2;
            if (v[m] == target) return true;
            else if (v[m] < target) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        int rl = 0, rh = matrix.size() - 1, rm;
        int cl = 0, ch = matrix[0].size() - 1, cm;
        while(rl <= rh && cl <= ch)
        {
            rm = (rl + rh) / 2;
            cm = (cl + ch) / 2;
            if (matrix[rm][cm] == target) return true;
            if (matrix[rm][cl] > target) rh = rm - 1;
            else if (matrix[rm][ch] < target) rl = rm + 1;
            else if (matrix[rl][cm] > target) ch = cm - 1;
            else if (matrix[rh][cm] < target) cl = cm + 1;
            else break;
        }
        if (rl <= rh && cl <= ch)
        {
            for (int i = rl; i <= rh; ++i)
                if (searchline(matrix[i], cl, ch, target)) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > m(1, vector<int>(1, -5));
    cout<<s.searchMatrix(m, -5)<<endl;
}
