class Solution {
public:
    int climbStairs(int n) {
        int d[100], i;
        d[1] = 1; d[2] = 2;
        for (i = 3; i <= n; ++i)
            d[i] = d[i - 1] + d[i - 2];
        return d[n];
    }
};
