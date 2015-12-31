class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int h1[300], h2[300], i;
        memset(h1, 0, sizeof(h1));
        memset(h2, 0, sizeof(h2));
        for (i = 0; i < s.size(); ++i)
        {
            if (h1[s[i]] != h2[t[i]]) return false;
            h1[s[i]] = i + s.size();
            h2[t[i]] = i + s.size();
        }
        return true;
    }
};
