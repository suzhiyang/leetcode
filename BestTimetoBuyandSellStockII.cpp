class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int i, r = 0;
        for (i = 0; i < prices.size() - 1; ++i)
            if (prices[i + 1] > prices[i]) r += prices[i + 1] - prices[i];
        return r;
    }
};
