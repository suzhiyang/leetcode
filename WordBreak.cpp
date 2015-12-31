class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> dp(s.size() + 1, false);
        int i, j;
        dp[0] = true;
        for (i = 1; i <= s.size(); ++i)
        {
            string t;
            for (j = 0; j < i; ++j)
            {
                if (dp[j])
                {
                    t = s.substr(j, i - j);
                    if (wordDict.find(t) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
