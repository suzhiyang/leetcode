#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int i, j, m = s1.size(), n = s2.size();
        bool **dp = new bool*[m + 1];
        for (i = 0; i <= m; ++i)
        {
            dp[i] = new bool[n + 1];
            memset(dp[i], 0, sizeof(bool) * (n + 1));
        }
        dp[0][0] = true;
        for (i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] & (s1[i - 1] == s3[i - 1]);
        for (j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] & (s2[j - 1] == s3[j - 1]);
        for (i = 1; i <= m; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                dp[i][j] = (dp[i - 1][j] & (s1[i - 1] == s3[i + j - 1])) |
                    (dp[i][j - 1] & (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    string s1, s2;
    s1 = "aabcc", s2 = "dbbca";
    cout<<s.isInterleave(s1, s2, "aadbbcbcac")<<endl;
    cout<<s.isInterleave(s1, s2, "aadbbbaccc")<<endl;
}
