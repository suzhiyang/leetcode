class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int i, min = INT_MAX, profit = 0, t;
        for(i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < min) min = prices[i];
            t = prices[i] - min;
            if (t > profit) profit = t;
        }
        return profit;
    }
};
