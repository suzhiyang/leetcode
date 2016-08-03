class Solution {
public:
    int bulbSwitch(int n) {
        int r = 0, p = 1;
        while(p <= n)
        {
            p <<= 1;
            ++r;
        }
        return r;
    }
};
