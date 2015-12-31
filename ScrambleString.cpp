#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
//        cout<<s1<<endl<<s2<<endl<<"==========="<<endl;
        if (s1 == s2) return true;
        int h[300], i;
        memset(h, 0, sizeof(h));
        for (i = 0; i < s1.size(); ++i)
        {
            ++h[s1[i]]; --h[s2[i]];
        }
        for (i = 0; i < 300; ++i)
            if (h[i] != 0) return false;

        for (i = 0; i < s1.size() - 1; ++i)
        {
            if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
                isScramble(s1.substr(i + 1), s2.substr(i + 1))) return true;
            if (isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) &&
                isScramble(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1))) return true;
        }
        return false;
    }
};

int main()
{
    cout<<Solution().isScramble("great","rgtae")<<endl;
}
