class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int r = 0, lowest = prices[0], i;
        for (i = 1; i < prices.size(); ++i)
        {
            lowest = min(lowest, prices[i]);
            r = max(r, prices[i] - lowest);
        }
        return r;
    }
};
