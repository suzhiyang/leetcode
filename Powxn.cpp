class Solution {
public:
    double myPow(double x, int n) {
        double r, t;
        if (n == 0) return 1.0;
        else if (n < 0) r = 1.0 / myPow(x, -(n + 1)) / x;
        else
        {
            t = myPow(x, n / 2);
            r = t * t;
            if (n % 2 != 0) r *= x;
        }
        return r;
    }
};
