#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int i, l, r, minl, minr, maxlen = 0;
        for (i = 0; i < s.size() - 1; ++i)
        {
            l = i; r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                --l; ++r;
            }
            if (r - l - 1 > maxlen)
            {
                maxlen = r - l - 1;
                minl = l + 1;
                minr = r - 1;
            }
            l = i; r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                --l; ++r;
            }
            if (r - l - 1 > maxlen)
            {
                maxlen = r - l - 1;
                minl = l + 1;
                minr = r - 1;
            }
        }
        return s.substr(minl, minr - minl + 1);
    }
};

int main()
{
    Solution s;
    string str = "abcaaa";
    cout<<s.longestPalindrome(str)<<endl;
    str = "abcaaacbc";
    cout<<s.longestPalindrome(str)<<endl;
    str = "aa";
    cout<<s.longestPalindrome(str)<<endl;
}
