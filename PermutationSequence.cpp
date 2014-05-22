#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Three step:
 * 1. start from the rightmost, find the first ordered sequence index i = 0 (132->13)
 * 2. start from the rightmost, find the first num index j = 1 greater than i = 0 (132->3)
 * 3. swap i,j, sort(i + 1, end)
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return string("1");
        string str;
        int i, j;
        for(i = 1; i <= n; ++i) str = str + (char)(i + '0');
        while(k--)
        {
            for(i = n - 2; i >= 0; --i)
                if (str[i] < str[i + 1]) break;
            for(j = n - 1; j > 0; --j)
                if (str[j] > str[i]) break;
            char t = str[i];
            str[i] = str[j];
            str[j] = t;
            sort(str.begin() + i + 1, str.end());
        }
        return str;
    }
};

int main()
{
    Solution s;
    cout<<s.getPermutation(3, 1)<<endl;
    cout<<s.getPermutation(3, 2)<<endl;
    cout<<s.getPermutation(3, 3)<<endl;
    cout<<s.getPermutation(3, 4)<<endl;
    cout<<s.getPermutation(3, 5)<<endl;
    cout<<s.getPermutation(3, 6)<<endl;
    cout<<s.getPermutation(9, 306490)<<endl;
}
