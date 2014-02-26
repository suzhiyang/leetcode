#include <iostream>

using namespace std;

class Solution {
private:
    int a[105][105];
public:
    Solution()
    {
        int i, j;
        for(i = 0; i < 102; ++i)
        {
            a[0][i] = 0;
            a[i][0] = 0;
        }
        a[0][1] = 1;
        for(i = 1; i < 102; ++i)
        {
            for(j = 1; j < 102; ++j)
            {
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
    }
    
    int uniquePaths(int m, int n) {
        return a[m][n];
    }
};

int main()
{
    Solution s;
    cout<<s.uniquePaths(3, 4)<<endl;
}
