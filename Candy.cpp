class Solution {
public:
    int candy(vector<int>& ratings) {
        int r, i;
        vector<int> candy(ratings.size(), 1);
        for (i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
        r = candy.back();
        for (i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) candy[i] = candy[i + 1] + 1;
            r += candy[i];
        }
        return r;
    }
};
