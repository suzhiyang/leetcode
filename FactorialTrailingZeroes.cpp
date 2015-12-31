class Solution {
public:
    int trailingZeroes(int n) {
        int t = 1, i, r = 0;
        while(t <= INT_MAX / 5)
        {
            t *= 5;
            r += n / t;
        }
        return r;
    }
};
