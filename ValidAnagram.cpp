class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int h[27], i;
        memset(h, 0, sizeof(h));
        for (i = 0; i < s.size(); ++i)
            ++h[s[i] - 'a'], --h[t[i] - 'a'];
        for (i = 0; i < 26; ++i)
            if (h[i] != 0) return false;
        return true;
    }
};
