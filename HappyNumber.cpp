class Solution {
public:
    bool isHappy(int n) {
        set<int> h;
        int t;
        while (n != 1)
        {
            if (h.count(n)) break;
            h.insert(n);
            t = 0;
            while (n != 0)
            {
                t = t + (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
        }
        return n == 1;
    }
};
