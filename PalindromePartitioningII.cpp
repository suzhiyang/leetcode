#include <vector>
#include <string>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    bool ispalindrome(string &s, int i, int j, vector<vector<int> > &p)
    {
        if (p[i][j] >= 0) return p[i][j];
        if (i == j) p[i][j] = 1;
        else if (i == j - 1)
        {
            if (s[i] == s[j]) p[i][j] = 1;
            else p[i][j] = 0;
        }
        else
        {
            p[i][j] = s[i] == s[j] && ispalindrome(s, i + 1, j - 1, p);
        }
        return p[i][j];
    }

    int minCut(string s) {
        vector<vector<int> > p(s.size(), vector<int>(s.size(), -1));
        int i, j;
        int *dp = new int[s.size()];
        dp[0] = 0;
        for (i = 1; i < s.size(); ++i)
        {
            if (ispalindrome(s, 0, i, p)) dp[i] = 0;
            else
            {
                dp[i] = INT_MAX;
                for (j = 0; j < i; ++j)
                {
                    if (ispalindrome(s, j + 1, i, p))
                        dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        for (i = 0; i < s.size(); ++i)
            cout<<dp[i]<<",";
        cout<<endl;
        return dp[s.size() - 1];
    }
};

int main()
{
    cout<<Solution().minCut("aaaaab")<<endl;
}
