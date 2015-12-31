class Solution {
public:
    int titleToNumber(string s) {
        int r = 0, m = 1, i;
        for (i = s.size() - 1; i >= 0; --i)
        {
            r = r + (s[i] - 'A' + 1) * m;
            m *= 26;
        }
        return r;
    }
};
