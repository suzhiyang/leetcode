class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s.rbegin(), s.rend());
        string p = s + "#" + rev;
        vector<int> pi(p.size(), 0);
        int k = 0, i;
        for (i = 1; i < p.size(); ++i)
        {
            while(k > 0 && p[k] != p[i])
                k = pi[k - 1];
            if (p[k] == p[i]) ++k;
            pi[i] = k;
        }
        return rev.substr(0, rev.size() - k) + s;
    }
};
