class Solution {
public:
    int romanToInt(string s) {
        map<char, int> h;
        h['M'] = 1000; h['D'] = 500; h['C'] = 100;
        h['L'] = 50; h['X'] = 10; h['V'] = 5; h['I'] = 1;
        int i, r = 0;
        for (i = s.size() - 1; i >= 0; --i)
        {
            if (i == s.size() - 1) r += h[s[i]];
            else
            {
                if (h[s[i]] >= h[s[i + 1]]) r += h[s[i]];
                else r -= h[s[i]];
            }
        }
        return r;
    }
};
