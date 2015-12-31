class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i;
        for (i = 0; i < 32; ++i)
            if ((m >> i) == (n >> i)) break;
        return m >> i << i;
    }
};
