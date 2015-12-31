class Solution {
public:
    int countPrimes(int n) {
        int p[2000000] = {0}, i, j, r = 0;
        for (i = 2; i < n; ++i)
        {
            if (p[i] == 0)
            {
                ++r;
                for (j = i * 2; j < n; j += i)
                    p[j] = 1;
            }
        }
        return r;
    }
};
