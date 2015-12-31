class Solution {
public:
    int reverse(int x) {
        int sign = 1, r = 0;
        if (x < 0)
        {
            sign = -1;
            x = -x;
        }
        while(x > 0)
        {
            if (r > INT_MAX / 10) return 0;
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r * sign;
    }
};
