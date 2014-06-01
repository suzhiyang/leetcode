#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int i, c = 0, sign = 1;
        if (divisor < 0)
        {
            divisor = -divisor;
            sign = -sign;
        }
        unsigned int d, a[40], b[40];
        if (dividend < 0)
        {
            d = -dividend;
            sign = -sign;
        }
        else d = dividend;
        a[0] = divisor;
        b[0] = 1;
        while(a[c] < d)
        {
            a[c + 1] = a[c] << 1;
            if (a[c + 1] < a[c]) break;
            b[c + 1] = b[c] << 1;
            ++c;
        }
        int r = 0;
        for(i = c; i >= 0; --i)
        {
            if (d >= a[i])
            {
                r += b[i];
                d -= a[i];
                ++i;
//                cout<<"# "<<b[i]<<" "<<a[i]<<" "<<dividend<<endl;
            }
        }
        if (sign == -1) r = -r;
        return r;
    }
};

int main()
{
    Solution s;
    int a, b;
    a = 200; b = 20;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 20000; b = 30;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 200; b = 400;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 200; b = -2;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 2147483647; b = 1;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 1038925803, b = -2147483648;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 1; b = 1;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = -10; b = -1;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = 1100540749; b = -1090366779;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
    a = -1566834001; b = 360941337;
    cout<<a<<"/"<<b<<"="<<s.divide(a, b)<<endl;;
}
