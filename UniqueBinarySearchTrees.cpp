#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        vector<int> c(n + 1, 0);
        int i, j;
        c[0] = 1;
        c[1] = 1;
        for(i = 2; i <= n; ++i)
        {
            for(j = 0; j < i; ++j)
            {
                c[i] += c[j] * c[i - j - 1];
            }
        }
        return c[n];
    }
};

int main()
{
}
