#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(1, 0);
        if (n < dp.size()) return dp[n];
        int i, j, t = dp.size();
        dp.resize(n + 1);
        for (i = t; i <= n; ++i)
        {
            dp[i] = i;
            for (j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 15; ++i)
        cout<<i<<":"<<s.numSquares(i)<<endl;
}
