#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int *dp = new int[n];
        dp[0] = 1;
        int i, p1 = 0, p2 = 0, p3 = 0;
        for (i = 1; i < n; ++i)
        {
            dp[i] = min(dp[p1] * 2, min(dp[p2] * 3, dp[p3] * 5));
            if (dp[i] == dp[p1] * 2) ++p1;
            if (dp[i] == dp[p2] * 3) ++p2;
            if (dp[i] == dp[p3] * 5) ++p3;
        }
        return dp[n - 1];
    }
};

int main()
{
    cout<<Solution().nthUglyNumber(7)<<endl;
}
