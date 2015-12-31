class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, maxp = 0, lowest, highest, r = 0;
        if (prices.size() < 2) return 0;
        lowest = prices[0];
        vector<int> l(prices.size(), 0);
        for (i = 1; i < prices.size(); ++i)
        {
            lowest = min(lowest, prices[i]);
            maxp = max(maxp, prices[i] - lowest);
            l[i] = maxp;
        }
        highest = prices.back();
        maxp = 0;
        for (i = prices.size() - 1; i > 0; --i)
        {
            highest = max(highest, prices[i]);
            maxp = maxp(maxp, highest - prices[i]);
            r = max(r, maxp + l[i - 1]);
        }
        r = max(r, highest - prices[0]);
        return r;
    }
};
