class Solution {
public:
    string addBinary(string a, string b) {
        if (b.size() > a.size()) swap(a, b);
        int i, bs = b.size(), as = a.size(), cy = 0;
        for (i = bs; i < as; ++i)
            b = "0" + b;
        string r(as, '0');
        for (i = as - 1; i >= 0; --i)
        {
            r[i] = a[i] - '0' + b[i] - '0' + cy;
            cy = r[i] / 2;
            r[i] = r[i] % 2 + '0';
        }
        if (cy == 1) r = "1" + r;
        return r;
    }
};
