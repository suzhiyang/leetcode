class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, cy = 0;
        vector<int> r(digits.size(), 0);
        for (i = digits.size() - 1; i >= 0; --i)
        {
            if (i == digits.size() - 1) r[i] = digits[i] + 1;
            else r[i] = digits[i] + cy;
            cy = r[i] / 10;
            r[i] %= 10;
        }
        if (cy == 1) r.insert(r.begin(), 1);
        return r;
    }
};
