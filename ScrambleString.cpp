#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i]) return false;
        return true;
    }
};

int main()
{
    string s1, s2;
    Solution s;
    s1 = "great";
    s2 = "reatg";
    cout<<s1<<":"<<s2<<":"<<s.isScramble(s1, s2)<<endl;
    return 0;
}
