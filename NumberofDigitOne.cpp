#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long m, c = 0, a, b;
        for (m = 1; m <= n; m *= 10)
        {
            a = n / m; b = n % m;
            if (a % 10 == 0) c += a / 10 * m;
            else if (a % 10 == 1) c += a / 10 * m + b + 1;
            else c += (a / 10 + 1) * m;
        }
        return c;
    }
};

int main()
{
    Solution s;
    cout<<s.countDigitOne(13)<<endl;
    cout<<s.countDigitOne(23)<<endl;
    cout<<s.countDigitOne(11)<<endl;
    cout<<s.countDigitOne(1410065408)<<endl;
}
