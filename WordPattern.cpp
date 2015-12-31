class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int h[26] = {0}, p = 0, i, j = 0;
        unordered_map<string, int> wh;
        for (i = 0; i <= str.size(); ++i)
        {
            if (i == str.size() || str[i] == ' ')
            {
                if (p >= pattern.size()) return false;
                string s = str.substr(j, i - j);
                if (wh[s] != h[pattern[p] - 'a']) return false;
                wh[s] = p + 1;
                h[pattern[p] - 'a'] = p + 1;
                ++p;
                j = i + 1;
            }
        }
        if (p < pattern.size()) return false;
        return true;
    }
};
