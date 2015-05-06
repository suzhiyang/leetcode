#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
//        cout<<s<<" "<<p<<endl;
        string t, f;
        int i, j;
        for (i = 0; i < p.size(); ++i)
        {
            if (p[i] == '.')
            {
                t += '.';
                f += '.';
            }
            else if (p[i] == '*')
                f[f.size() - 1] = '*';
            else
            {
                t += p[i];
                f += '0';
            }
        }
        
        int **d = new int *[s.size() + 1];
        for (i = 0; i <= s.size(); ++i)
            d[i] = new int[t.size() + 1];
        for (i = 0; i <= s.size(); ++i)
        {
            for (j = 0; j <= t.size(); ++j)
                d[i][j] = 0;
        }
        d[s.size()][t.size()] = 1;
        for (j = f.size() - 1; j >= 0; --j)
        {
            if (f[j] == '*') d[s.size()][j] = 1;
            else break;
        }
        for (i = s.size() - 1; i >= 0; --i)
        {
            for (j = t.size() - 1; j >= 0; --j)
            {
                if (f[j] == '0' && s[i] == t[j]) d[i][j] = d[i + 1][j + 1];
                else if (f[j] == '*')
                {
                    if (t[j] == '.') d[i][j] = d[i + 1][j + 1] | d[i][j + 1] | d[i + 1][j];
                    else
                    {
                        if (s[i] == t[j]) d[i][j] = d[i + 1][j + 1] | d[i][j + 1] | d[i + 1][j];
                        else d[i][j] = d[i][j + 1];
                    }
                    
                }
                else if (f[j] == '.') d[i][j] = d[i + 1][j + 1];
            }
        }
        for (j = 0; j <= t.size(); ++j)
        {
            for (i = 0; i <= s.size(); ++i)
                cout<<d[i][j]<<" ";
            cout<<endl;
        }
        return d[0][0];
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa","a*")<<endl;
    cout<<s.isMatch("aa",".*")<<endl;
    cout<<s.isMatch("ab",".*")<<endl;
    cout<<s.isMatch("aab","c*a*b")<<endl;
    cout<<s.isMatch("aab","c*.*b")<<endl;
    cout<<s.isMatch("abbbb","c*ab*")<<endl;
    cout<<s.isMatch("abbbb","a*b*")<<endl;
    // wrong answer
    cout<<s.isMatch("a","ab*")<<endl;
    cout<<s.isMatch("ba",".*a*a")<<endl;
}
