#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j;
        bool **dp = new bool*[s.size() + 1];
        for (i = 0; i < s.size() + 1; ++i)
        {
            dp[i] = new bool[p.size() + 1];
            memset(dp[i], 0, sizeof(bool) * (p.size() + 1));
        }
        dp[0][0] = true;
        for (i = 1; i < s.size() + 1; ++i)
            dp[i][0] = false;
        for (j = 1; j < p.size() + 1; ++j)
        {
            if (dp[0][j - 1] && p[j - 1] == '*') dp[0][j] = true;
            else dp[0][j] = 0;
        }
        for (i = 1; i < s.size() + 1; ++i)
        {
            for (j = 1; j < p.size() + 1; ++j)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j] | dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if (p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
//         for (i = 0; i < s.size() + 1; ++i)
//         {
//             for (j = 0; j < p.size() + 1; ++j)
//                 cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }
        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aab", "a*b*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    cout<<s.isMatch("ab", "?*")<<endl;
    cout<<s.isMatch("aaaababbbaaabaabbbbabaababaabbabbaabababbaaaaaaabba", "baaaaba*****b***ab******")<<endl;

//     cout<<"##############################"<<endl;
//     int **dp = new int*[5];
//     for (int i = 0; i < 5; ++i)
//     {
//         dp[i] = new int[10];
//         if (i > 0) cout<<(long long)(static_cast<const void *>(dp[i])) - (long long)(static_cast<const void *>(dp[i - 1]))<<endl;
//     }
//     cout<<sizeof(int) * 8<<endl;
//     cout<<sizeof(dp[0])<<endl;
//     int t[5];
//     cout<<sizeof(t)<<endl;
//     cout<<sizeof(int) * 5<<endl;
//     int d[5][6];
//     cout<<sizeof(d[0])<<endl;
}
