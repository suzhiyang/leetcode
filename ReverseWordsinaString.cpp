#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // Trim spaces first
        int l = 0, i = 0;
        for (i = 0; i < s.length(); ++i)
            if (s[i] != ' ') break;
        for (; i < s.length(); ++i)
        {
            if (s[i] != ' ') s[l++] = s[i];
            else
            {
                for (; i < s.length(); ++i)
                    if (s[i] != ' ') break;
                if (i < s.length())
                {
                    s[l++] = ' ';
                    --i;
                }
            }
        }
        s.erase(s.begin() + l, s.end());

        // Reverse 2 times
        char t;
        for (i = 0; i < s.length() / 2; ++i)
        {
            t = s[i];
            s[i] = s[s.length() - 1 - i];
            s[s.length() - 1 - i] = t;
        }
        int b = 0, e = 0;
        for (i = 0; i < s.length();)
        {
            if (s[i] != ' ') b = i;
            else b = ++i;
            while(s[i++] != ' ' && i < s.length());
            e = i - 1;
            if (i < s.length()) --e;
            while(b < e)
            {
                t = s[b];
                s[b] = s[e];
                s[e] = t;
                ++b;
                --e;
            }
        }
    }
};

int main()
{
    string str = "   the     sky is  blue color ";
    Solution s;
    cout<<str<<endl;
    s.reverseWords(str);
    cout<<str<<endl;
    return 0;
}
