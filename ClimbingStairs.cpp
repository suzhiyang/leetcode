#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a[10000] = {0}, i;
        a[1] = 1;
        a[2] = 2;
        for (i = 3; i < n + 1; ++i)
            a[i] = a[i - 1] + a[i - 2];
        return a[n];
    }
};

int main()
{
}
