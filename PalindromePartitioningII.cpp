class Solution {
public:
    int minCut(string s) {
        int l = s.size(), i, j;
        bool p[l][l];
        memset(p, 0, l * l * sizeof(bool));
        for (i = l - 1; i >= 0; --i)
        { 
            for (j = i; j < l; ++j)
            {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                    p[i][j] = true;
            }
        }
        int c[l];
        c[0] = 0;
        for (i = 1; i < l; ++i)
        {
            c[i] = i;
            if (p[0][i] == true) c[i] = 0;
            for (j = 0; j < i; ++j)
            {
                if (p[j + 1][i] == true)
                    c[i] = min(c[i], c[j] + 1);
            }
        }
        return c[l - 1];
    }
};

