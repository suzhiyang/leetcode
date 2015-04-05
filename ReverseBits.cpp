#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int l = 31, r = 0;
        int bl = 1<<31, br = 1;
        while(l > r)
        {
            if ((n & bl) >> l != (n & br) >> r)
                n = n ^ bl ^ br;
            --l; ++r;
            bl = 1<<l; br = 1<<r;
        }
        return n;
    }
};

int main()
{
    uint32_t a = 43261596;
    Solution s;
    cout<<s.reverseBits(a)<<endl;
}
