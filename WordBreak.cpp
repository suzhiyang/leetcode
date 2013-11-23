#include <tr1/unordered_set>
#include <vector>
#include <iostream>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0, j = 0, len = s.size();
        vector<int> seg(len + 1, 0);
        seg[0] = 1;
        string sub;
        unordered_set<string>::const_iterator it;
        for (i = 1; i <= len; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                sub = s.substr(j, i - j);
//                cout<<"["<<j<<","<<i<<"]"<<sub<<endl;
                it = dict.find(sub);
                if (it != dict.end() && seg[j] == 1)
                {
                    seg[i] = 1;
                    break;
                }
            }
        }
        if (seg[len] == 1) return true;
        else return false;
    }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    string str("leetcode");
    Solution s;
    cout<<s.wordBreak(str, dict)<<endl;

    dict.clear();
    dict.insert("aa");
    dict.insert("aaa");
    str = "aaaaaaaab";
    cout<<s.wordBreak(str, dict)<<endl;
}
