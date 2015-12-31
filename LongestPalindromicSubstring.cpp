class Solution {
public:
    string longestPalindrome(string s) {
        int i, l, r;
        string res;
        for (i = 0; i < s.size(); ++i)
        {
            l = i; r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {--l; ++r;}
            if (l < r) {++l; --r;}
            if (r - l + 1 > res.size()) res = s.substr(l, r - l + 1);
            if (i + 1 < s.size() && s[i] == s[i + 1])
            {
                l = i; r = i + 1;
                while(l >= 0 && r < s.size() && s[l] == s[r]) {--l; ++r;}
                if (l < r) {++l; --r;}
                if (r - l + 1 > res.size()) res = s.substr(l, r - l + 1);
            }
        }
        return res;
    }
};
