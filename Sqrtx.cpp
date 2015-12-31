class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, m;
        while (l < r)
        {
            m = l + (r - l) / 2;
            if (m * m > x) r = m - 1;
            else
            {
                if ((m + 1) * (m + 1) > x) return m;
                l = m + 1;
            }
        }
    }
};
