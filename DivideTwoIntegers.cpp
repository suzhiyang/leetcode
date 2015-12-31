#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d1 = (long long)dividend, d2 = (long long)divisor;
        if (dividend < 0) d1 = -d1;
        if (divisor < 0) d2 = -d2;
        long long r = 0, t = d2, i;
        vector<long long> d;
        while(t <= d1)
        {
            d.push_back(t);
            t = t << 1;
        }
        for (i = d.size() - 1; i >= 0; --i)
        {
            if (d1 >= d[i])
            {
                d1 -= d[i];
                r += (1ul << i);
            }
        }
        if ((dividend > 0) ^ (divisor > 0)) r = -r;
        if (r > INT_MAX || r < INT_MIN) return INT_MAX;
        return r;
    }
};

int main()
{
    Solution s;
    cout<<s.divide(100, 3)<<endl;
    cout<<s.divide(100, 1)<<endl;
    cout<<s.divide(1, -1)<<endl;
    cout<<s.divide(2147483647, 1)<<endl;
    cout<<s.divide(-2147483648, -1)<<endl;
    cout<<s.divide(-2147483648, 1)<<endl;
}
