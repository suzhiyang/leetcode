#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void buildtable(string &s, int *pi)
    {
        int i, k = 0;
        pi[0] = 0;
        for (i = 1; i < s.size(); ++i)
        {
            while(k > 0 && s[k] != s[i])
                k = pi[k - 1];
            if (s[k] == s[i]) k = k + 1;
            pi[i] = k;
        }
    }
    
    string shortestPalindrome(string s) {
        int i;
        string r(s.rbegin(), s.rend());
        int *pi = new int[s.size()];
        buildtable(s, pi);
        int k = 0;
        for (i = 0; i < r.size(); ++i)
        {
            while (k > 0 && r[i] != s[k])
                k = pi[k - 1];
            if (r[i] == s[k])
                k = k + 1;
        }
        r = r + s.substr(k);
//        delete []pi;
        return r;
    }
};

int main()
{
    Solution s;
    string str;
    str = "abcd";
    cout<<str<<":"<<s.shortestPalindrome(str)<<endl;
    str = "aacecaaa";
    cout<<str<<":"<<s.shortestPalindrome(str)<<endl;
    str = "a";
    cout<<str<<":"<<s.shortestPalindrome(str)<<endl;
    str = "ababbbabbaba";
    cout<<str<<":"<<s.shortestPalindrome(str)<<endl;
}
