class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int l = 31, r = 0;
        while(l > r)
        {
            if (((n >> l) & 1) != ((n >> r) & 1))
            {
                n = n ^ (1 << l);
                n = n ^ (1 << r);
            }
            --l; ++r;
        }
        return n;
    }
};
