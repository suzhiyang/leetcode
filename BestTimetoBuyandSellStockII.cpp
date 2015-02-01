class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int i, min = INT_MAX, profit = 0, t;
        for(i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
