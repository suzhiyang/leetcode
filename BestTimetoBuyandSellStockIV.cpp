#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int i, j, n = prices.size(), t;

        if (k >= n / 2)
        {
            int r = 0;
            for (i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1]) r += prices[i] - prices[i - 1];
            return r;
        }
        
        int **dp = new int*[n];
        for (i = 0; i < n; ++i)
        {
            dp[i] = new int[k + 1];
            memset(dp[i], 0, sizeof(int) * (k + 1));
        }
        for (j = 1; j <= k; ++j)
        {
            t = -prices[0];
            for (i = 1; i < n; ++i)
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], prices[i] + t);
                t = max(t, dp[i][j - 1] - prices[i]);
            }
        }
        // for (j = 0; j <= k; ++j)
        // {
        //     for (i = 0; i < n; ++i)
        //         cout<<dp[i][j]<<",";
        //     cout<<endl;
        // }
        return dp[n - 1][k];
    }
};

int main()
{
    int a[] = {1,2,4,2,5,7,2,4,9,0,9};
    vector<int> p(a, a + sizeof(a) / sizeof(int));
    cout<<Solution().maxProfit(2, p)<<endl;
    int b[] = {1,2,4,2,5,7,2,4,9,0};
    p.assign(b, b + sizeof(b) / sizeof(int));
    cout<<Solution().maxProfit(4, p)<<endl;
}
