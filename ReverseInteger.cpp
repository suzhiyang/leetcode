#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int r = 0, a = x, sign = 1, s[10] = {0};
        if (a < 0)
        {
            a = -x;
            sign = -1;
        }
        int i = 0, j;
        while (a > 0)
        {
            s[i++] = a % 10;
            a /= 10;
        }
        for (j = 0; j < i; ++j)
            r = r * 10 + s[j];
        r *= sign;
        return r;
    }
};


int main()
{
    Solution s;
    cout<< s.reverse(300)<<endl;
    cout<< s.reverse(332)<<endl;
    cout<< s.reverse(-9332)<<endl;
    cout<< s.reverse(0)<<endl;
}
