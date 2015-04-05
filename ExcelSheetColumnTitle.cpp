#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string title;
        int d, r = n;
        while(n)
        {
            r = n % 26;
            n /= 26;
            if (r == 0) {--n; r = 26;}
            title += (char)(r - 1 + 'A');
        }
        int i = 0, j = title.size() - 1;
        while(i < j)
        {
            d = title[i];
            title[i] = title[j];
            title[j] = d;
            ++i; --j;
        }
        return title;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 720; ++i)
        cout<<i<<" "<<s.convertToTitle(i)<<endl;
}
