#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> p(primes.size(), 0), dp(n, 1);
        ll i, j, m;
        for (i = 1; i < n; ++i)
        {
            m = INT_MAX;
            for (j = 0; j < p.size(); ++j)
                m = min(m, dp[p[j]] * primes[j]); 
            for (j = 0; j < p.size(); ++j)
                if (dp[p[j]] * primes[j] == m) ++p[j];
            dp[i] = m;
        }
        return dp[n - 1];
    }
};

int main()
{
    int a[] = {2, 7, 13, 19};
    vector<int> v(a, a + 4);
    Solution().nthSuperUglyNumber(12, v);
}
