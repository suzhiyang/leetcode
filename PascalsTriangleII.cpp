class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>();
        vector<int> r(rowIndex + 1, 0);
        r[0] = 1;
        int i, j;
        for (i = 1; i <= rowIndex; ++i)
        {
            for (j = rowIndex; j > 0; --j)
                r[j] += r[j - 1];
        }
        return r;
    }
};
