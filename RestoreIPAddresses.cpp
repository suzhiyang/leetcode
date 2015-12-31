#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(vector<string> &r, string &s, string cur, int pos, int num, int dots)
    {
//        cout<<cur<<endl;
        if (pos >= s.size())
        {
            if (dots == 3 && num >= 0 && num <= 255 && cur.size() > 0 && *cur.rbegin() != '.')
                r.push_back(cur);
        }
        else
        {
            if (cur.size() > 0 && *cur.rbegin() != '.') dfs(r, s, cur + ".", pos, 0, dots + 1);
            if (cur.size() > 0 && *cur.rbegin() == '0' && num == 0) return;
            num = num * 10 + s[pos] - '0';
            if (num > 255) return;
            dfs(r, s, cur + s[pos], pos + 1, num, dots);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        if (s.size() > 12) return r;
        dfs(r, s, string(), 0, 0, 0);
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> r;
//    r = s.restoreIpAddresses("25525511135");
    r = s.restoreIpAddresses("010010");
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
}   
