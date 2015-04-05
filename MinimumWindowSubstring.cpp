#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int hash[300], dict[300], s = 0, i, j, c = 0, min = INT_MAX, ms = 0, me = -1;
        for (i = 0; i < 300; ++i) {hash[i] = 0; dict[i] = 0;}
        for (i = 0; i < T.size(); ++i) ++dict[T[i]];
        for (i = 0; i < S.size(); ++i)
        {
            if (dict[S[i]] > 0)
            {
                if (hash[S[i]] < dict[S[i]]) ++c;
                ++hash[S[i]];
                if (c == T.size())
                {
                    for (j = s; j <= i; ++j)
                    {
                        if (dict[S[j]] == 0) continue;
                        if (hash[S[j]] == dict[S[j]])
                        {
                            s = j;
                            break;
                        }
                        else if (hash[S[j]] > dict[S[j]]) --hash[S[j]];
                    }
                    if (i - s < min)
                    {
                        min = i - s;
                        ms = s;
                        me = i;
                    }
                }
            }
        }
        string r;
        for (i = ms; i <= me; ++i)
            r += S[i];
        return r;
    }
};

int main()
{
    Solution s;
    string a, b;
    a = "ADOBECODEBANC";
    b = "ABC";
    cout<<s.minWindow(a, b)<<endl;
    a = "a";
    b = "aa";
    cout<<s.minWindow(a, b)<<endl;
    a = "ab";
    b = "b";
    cout<<s.minWindow(a, b)<<endl;
}
