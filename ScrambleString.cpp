class Solution {
public:
    bool isScramble(string s1, string s2) {
        int h[26], i, s = s1.size();
        memset(h, 0, 26 * sizeof(int));
        for (i = 0; i < s1.size(); ++i)
        {
            ++h[s1[i] - 'a'];
            --h[s2[i] - 'a'];
        }
        for (i = 0; i < 26; ++i)
            if (h[i] != 0) return false;
        if (s1.size() == 1 && s2.size() == 1) return true;
        for (i = 1; i < s1.size(); ++i)
        {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(s - i)) && isScramble(s1.substr(i), s2.substr(0, s - i)))) return true;
        }
        return false;
    }
};
