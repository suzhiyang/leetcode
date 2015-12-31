class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0, i;
        for (i = 0; i < 32; ++i)
            c += ((n>>i) & 1);
        return c;
    }
};
