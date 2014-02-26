#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> restore(string s, int segcount)
    {
        vector<string> r;
        int n;
        if (segcount == 1)
        {
            n = atoi(s.c_str());
            if (s.size() > 1 && s[0] == '0') return r;
            if (n >= 0 && n <= 255)
                r.push_back(s);
            return r;
        }
        string prestr, poststr;
        for (int i = 1; i <= 3 && i <= s.size(); ++i)
        {
            prestr = s.substr(0, i);
            if (i > 1 && s[0] == '0') break;
            n = atoi(prestr.c_str());
            if (n >= 0 && n <= 255)
            {
                poststr = s.substr(i);
                if (poststr == "") break;
                vector<string> t = restore(poststr, segcount - 1);
                if (!t.empty())
                {
                    for (int j = 0; j < t.size(); ++j)
                    {
                        string tempstr = prestr + "." + t[j];
                        r.push_back(tempstr);
                    }
                }
            }
        }
        return r;
    }
    
    vector<string> restoreIpAddresses(string s) {
        return restore(s, 4);
    }
};

int main()
{
    string str = "25525511135";
    Solution s;
    vector<string> r = s.restoreIpAddresses(str);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;

    str = "0000";
    r = s.restoreIpAddresses(str);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;

    str = "010010";
    r = s.restoreIpAddresses(str);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
    return 0;
}
