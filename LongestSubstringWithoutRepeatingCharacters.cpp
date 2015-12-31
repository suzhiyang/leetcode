class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int h[260] = {0};
        int mx = 0, l = 0, r = 0;
        for (r = 0; r < s.size(); ++r)
        {
            if (h[s[r]] == 0)
            {
                h[s[r]] = 1;
                if (r - l + 1> mx) mx = r - l + 1;
            }
            else
            {
                while(s[l] != s[r])
                {
                    h[s[l]] = 0;
                    ++l;
                }
                ++l;
            }
        }
        return mx;
    }
};
