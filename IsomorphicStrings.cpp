class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i, h1[500], h2[500];
        memset(h1, 0, 500 * sizeof(int));
        memset(h2, 0, 500 * sizeof(int));
        for (i = 0; i < s.size(); ++i)
        {
            if (h1[s[i]] != h2[t[i]]) return false;
            h1[s[i]] = i + 1; h2[t[i]] = i + 1;
        }
        return true;
    }
};
