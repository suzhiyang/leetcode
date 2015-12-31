#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         string t, np;
//         int i, j;
//         for (i = 0;i < p.size(); ++i)
//         {
//             if (p[i] == '*') t.back() = '*';
//             else
//             {
//                 np += p[i];
//                 t += '0';
//                 if (p[i] == '.') t.back() = '.';
//             }
//         }
//         vector<vector<int> > d(s.size() + 1, vector<int>(np.size() + 1, 0));
//         d[0][0] = 1;
//         for (j = 1; j < np.size() + 1; ++j)
//         {
//             if (t[j - 1] == '*') d[0][j] = 1;
//             else break;
//         }
//         for (i = 1; i < s.size() + 1; ++i)
//         {
//             for (j = 1; j < np.size() + 1; ++j)
//             {
//                 if (t[j - 1] == '0')
//                 {
//                     if (s[i - 1] == np[j - 1]) d[i][j] = d[i - 1][j - 1];
//                     else d[i][j] = 0;
//                 }
//                 else if (t[j - 1] == '.')
//                     d[i][j] = d[i - 1][j - 1];
//                 else if (t[j - 1] == '*')
//                 {
//                     if (s[i - 1] == np[j - 1] || np[j - 1] == '.') d[i][j] = d[i - 1][j - 1] | d[i - 1][j] | d[i][j - 1];
//                     else d[i][j] = d[i][j - 1];
//                 }
//             }
//         }
// //         cout<<t<<endl;
// //         cout<<np<<endl;
// //         for (i = 0; i < s.size() + 1; ++i)
// //         {
// //             for (j = 0; j < np.size() + 1; ++j)
// //                 cout<<d[i][j]<<" ";
// //             cout<<endl;
// //         }
//         return d[s.size()][np.size()];
//     }
// };

class Solution {
public:
    bool match(string &s, string &p, int i, int j)
    {
        if (i == 0 && j == 0) return true;
        if (i == 0)
        {
            if (p[j - 1] == '*') return match(s, p, i, j - 2);
            else return false;
        }
        if (j == 0) return false;
        bool r = false;
        if (p[j - 1] == '*')
        {
            if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                r = r || match(s, p, i - 1, j - 2) || match(s, p, i, j - 2) || match(s, p, i - 1, j);
            else r = r | match(s, p, i, j - 2);
        }
        else if (p[j - 1] == '.') r = r | match(s, p, i - 1, j - 1);
        else if (s[i - 1] == p[j - 1]) r = r | match(s, p, i - 1, j - 1);
        return r;
    }
    
    bool isMatch(string s, string p) {
        return match(s, p, s.size(), p.size());
    }
};

int main()
{
    Solution sol;
    string s, p;
    s = "aac", p = "a*c";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "aac", p = ".*";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "aasdfasdfasdfasdfas", p = "aasdf.*asdf.*asdf.*asdf.*s";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "baabbbaccbccacacc", p = "c*..b*a*a.*a..*c";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "badc", p = "c*..b*a*a.*a..*c";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "aaaaaaaaaaaaab", p = "a*a*a*a*a*a*a*a*a*a*a*a*b";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
    s = "aaa", p = "ab*a";
    cout<<s<<":"<<p<<" "<<sol.isMatch(s, p)<<endl;
}
   
