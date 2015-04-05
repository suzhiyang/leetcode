class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        else if (num.size() == 1) return num[0];
        else if (num.size() == 2) return max(num[0], num[1]);
        int d1 = num[0], d2 = max(num[0], num[1]), i, d;
        for (i = 2; i < num.size(); ++i)
        {
            d = max(d2, d1 + num[i]);
            d1 = d2;
            d2 = d;
        }
        return d;
    }
};
