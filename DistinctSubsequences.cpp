#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int i, j;
        int **d = new int* [T.size() + 1];
        for (i = 0; i <= T.size(); ++i)
            d[i] = new int[S.size() + 1];
        d[0][0] = 1;
        for (i = 1; i <= T.size(); ++i)
            d[i][0] = 0;
        for (j = 1; j <= S.size(); ++j)
            d[0][j] = 1;
        for (i = 1; i <= T.size(); ++i)
        {
            for (j = 1; j <= S.size(); ++j)
            {
                d[i][j] = d[i][j - 1];
                if (T[i - 1] == S[j - 1]) d[i][j] += d[i - 1][j - 1];
            }
        }
//         for (i = 0; i <= T.size(); ++i)
//         {
//             for (j = 0; j <= S.size(); ++j)
//                 cout<<d[i][j]<<" ";
//             cout<<endl;
//         }
        return d[T.size()][S.size()];
    }
};

int main()
{
    Solution s;
    string S = "rabbbit", T = "rabbit";
    S = "b", T = "b";
    cout<<s.numDistinct(S, T)<<endl;
}
