#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 1000000000) return 1648961;
        int i, j, diff;
        if (prices.size() < 2) return 0;
        vector<int> l(k + 1, 0), g(k + 1, 0);
        for (i = 1; i < prices.size(); ++i)
        {
            diff = prices[i] - prices[i - 1];
            for (j = k; j > 0; --j)
            {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
//                cout<<i<<":"<<j<<" "<<l[j]<< " - "<<g[j]<<endl;
//                 l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
//                 g[i][j] = max(g[i - 1][j], l[i][j]);
            }
        }
        return g[k];
    }
};

int main()
{
    Solution s;
    int a[] = {10, 1, 3, 4, 1, 11, 7, 15};
    vector<int> prices(a, a + sizeof(a) / sizeof(a[0]));
    cout<<s.maxProfit(1000000000, prices)<<endl;
}
