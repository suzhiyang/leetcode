#include <iostream>

using namespace std;

class Solution {
public:
    double positivepow(double x, unsigned int n)
    {
        if (n == 0) return 1;
        double r;
        if (n % 2 == 0)
        {
            r = positivepow(x, n / 2);
            r *= r;
        }
        else
        {
            r = positivepow(x, (n - 1) / 2);
            r = r * r * x;
        }
        return r;
    }
    
    double pow(double x, int n) {
        if (n == 0) return 1;
        double r;
        if (n < 0)
        {
            r = positivepow(x, (unsigned int)(-n));
            r = 1 / r;
        }
        else r = positivepow(x, n);
        return r;
    }
};

int main()
{
    Solution s;
    cout<<s.pow(3, 4)<<endl;
    cout<<s.pow(3, 5)<<endl;
    cout<<s.pow(3.22, 2)<<endl;
    cout<<s.pow(3.223, -5)<<endl;
    cout<<s.pow(1.0, -2147483648)<<endl;
}
