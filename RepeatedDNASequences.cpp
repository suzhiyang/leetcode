#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int h[1024 * 1024 + 1];

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;
        memset(h, 0, sizeof(h));
        if (s.size() <= 10) return r;
        int i, j;
        unsigned int t = 0;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A') t = (t << 2);
            else if (s[i] == 'C') t = (t << 2) | 1;
            else if (s[i] == 'G') t = (t << 2) | 2;
            else t = (t << 2) | 3;
            if (i >= 9)
            {
                t = t & (~0u >> 12);
                if (h[t] == 1) r.push_back(s.substr(i - 9, 10));
                ++h[t];
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> r = s.findRepeatedDnaSequences("AAAAAAAAAAAA");
    r = s.findRepeatedDnaSequences("GAGAGAGAGAG");
    r = s.findRepeatedDnaSequences("AAAAAAAAAAA");
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
    cout<<endl;
}
