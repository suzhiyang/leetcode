#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int mi = -1, ml = INT_MAX, cnt = 0, h[300], c[300];
        memset(h, 0, sizeof(h));
        memset(c, 0, sizeof(c));
        int i, j;
        for (i = 0; i < t.size(); ++i)
            ++h[t[i]];
        i = 0; j = 0;
        while(j < s.size())
        {
            if (h[s[j]] > 0)
            {
                ++c[s[j]];
                if (c[s[j]] <= h[s[j]]) ++cnt;
                if (cnt == t.size())
                {
                    while (i <= j)
                    {
                        if (h[s[i]] > 0)
                        {
                            if (c[s[i]] == h[s[i]])
                            {
                                if (j - i + 1 < ml)
                                {
                                    mi = i;
                                    ml = j - i + 1;
                                }
                                break;
                            }
                            else --c[s[i]];
                        }
                        ++i;
                    }
                }
            }
            ++j;
        }
        if (mi == -1) return "";
        return s.substr(mi, ml);
    }
};

int main()
{
    string s, t;
    Solution sol;
    s = "a", t = "a";
    cout<<sol.minWindow(s, t)<<endl;
    s = "ADOBECODEBANC", t = "ABC";
    cout<<sol.minWindow(s, t)<<endl;
    s = "aacbb", t = "aab";
    cout<<sol.minWindow(s, t)<<endl;
}
