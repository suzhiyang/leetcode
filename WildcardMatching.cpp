#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
//     bool isMatch(string s, string p) {
//         cout<<s<<" "<<p<<endl;
//         int i, j;
//         int *d = new int[p.size() + 1];
//         memset(d, 0, sizeof(d) * sizeof(int));
//         d[p.size()] = 1;
//         for (j = p.size() - 1; j >= 0; --j)
//         {
//             if (p[j] == '*') d[j] = 1; // d[s.size()][j] = 1;
//             else break;
//         }
//         for (j = 0; j <= p.size(); ++j)
//             cout<<d[j]<<" ";
//         cout<<endl;
//         for (i = s.size() - 1; i >= 0; --i)
//         {
//             if (p[j] ==
//             for (j = 0; j < p.size(); ++j)
//             {
//                 if (p[j] == '?') d[j] = d[j + 1]; // d[i][j] = d[i + 1][j + 1];
//                 else if (p[j] == '*')  d[j] = d[j] | d[j + 1]; // d[i][j] = d[i][j + 1] | d[i + 1][j] | d[i + 1][j + 1];
//                 else if (s[i] == p[j]) d[j] = d[j + 1];// d[i][j] = d[i + 1][j + 1];
//                 else d[j] = 0;
//             }
//             for (j = 0; j <= p.size(); ++j)
//                 cout<<d[j]<<" ";
//             cout<<endl;
//         }
//         return d[0];
//     }
    
    bool isMatch(string s, string p) {
        cout<<s<<" "<<p<<endl;
        int i, j;
//        vector<vector<int> > d(s.size() + 1, vector<int>(p.size() + 1, 0));
        bool **d = new bool *[s.size() + 1];
        for (i = 0; i <= s.size(); ++i)
        {
            d[i] = new bool[p.size() + 1];
            for (j = 0; j <= p.size(); ++j)
                d[i][j] = false;
        }
        d[s.size()][p.size()] = true;
        for (j = p.size() - 1; j >= 0; --j)
        {
            if (p[j] == '*') d[s.size()][j] = true;
            else break;
        }
        for (i = s.size() - 1; i >= 0; --i)
        {
            for (j = p.size() - 1; j >= 0; --j)
            {
                if (p[j] == '?') d[i][j] = d[i + 1][j + 1];
                else if (p[j] == '*') d[i][j] = d[i][j + 1] | d[i + 1][j] | d[i + 1][j + 1];
                else if (s[i] == p[j]) d[i][j] = d[i + 1][j + 1];
            }
        }
//         for (i = 0; i <= s.size(); ++i)
//         {
//             for (j = 0; j <= p.size(); ++j)
//                 cout<<d[i][j]<<" ";
//             cout<<endl;
//         }
        return d[0][0];
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa","*")<<endl;
    cout<<s.isMatch("aa","a*")<<endl;
    cout<<s.isMatch("ab","?*")<<endl;
    cout<<s.isMatch("aab","c*a*b")<<endl;
    // own cases
    cout<<s.isMatch("aab","a*?b")<<endl;
    cout<<s.isMatch("aabcdkjs","a*?*")<<endl;
    cout<<s.isMatch("aabjk","*jjj?")<<endl;
    cout<<s.isMatch("djk","*jj*")<<endl;
    cout<<s.isMatch("djk","*j*?")<<endl;
}
