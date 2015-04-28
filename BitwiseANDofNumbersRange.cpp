#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = 31; i >= 0; --i)
            if (m>>i != n>>i) return m & (~0<<i);
    }
};

int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(600000000, 2147483645)<<endl;
    cout<<s.rangeBitwiseAnd(1, 1)<<endl;
    cout<<s.rangeBitwiseAnd(10, 15)<<endl;
}
