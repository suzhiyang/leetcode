#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int c = 0, i, p;
        int *a = new int[n];
        memset(a, 0, n * sizeof(int));
        for (p = 2; p < int(sqrt(n)) + 1; ++p)
        {
            if (a[p] == 0)
            {
                ++c;
                for (i = p * 2; i < n; i += p)
                    a[i] = 1;
            }
        }
        for (; p < n; ++p)
            if (a[p] == 0) ++c;
        return c;
    }
};

int main()
{
    Solution s;
    cout<<s.countPrimes(5)<<endl;
    cout<<s.countPrimes(15)<<endl;
}
