#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        int a = x, n = 1;
        while(a > 100)
        {
            a /= 100;
            n *= 10;
        }
        double cur, last;
        if (a < 10) cur = 2.0 * n;
        else cur = 6.0 * n;
        last = cur;
        while(true)
        {
            cur = 0.5 * (last + x / last);
            if (fabs(last - cur) < 0.001) break;
            last = cur;
        }
        return int(last);
    }
};

int main()
{
    Solution s;
    cout<<s.sqrt(6)<<endl;
    cout<<s.sqrt(60)<<endl;
    cout<<s.sqrt(600)<<endl;
    cout<<s.sqrt(6000)<<endl;
    cout<<s.sqrt(60000)<<endl;
    cout<<s.sqrt(2147395599)<<endl;
}
