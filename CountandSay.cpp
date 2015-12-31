#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string l = countAndSay(n - 1), r;
        int i, j = 0;
        for (i = 0; i < l.size();)
        {
            while (i < l.size() && l[i] == l[j]) ++i;
            stringstream ss;
            ss<<(i - j)<<l[j];
            r += ss.str();
            j = i;
        }
        return r;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 10; ++i)
        cout<<s.countAndSay(i)<<endl;
}
