#include <iostream>
#include <string>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int st = 0, ed = 0, len = s.size();
        string sub;
        unordered_set<string>::const_iterator it;
        for(st = 0; st < len;)
        {
            for (ed = len - 1; ed >= st; --ed)
            {
                sub = s.substr(st, ed - st + 1);
                cout<<sub<<endl;
                it = dict.find(sub);
                if (it != dict.end())
                {
                    st = ed + 1;
                    break;
                }
            }
            if (it == dict.end()) return false;
        }
        return true;
    }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    string s("leetcode");
    Solution solution;
    bool b = solution.wordBreak(s, dict);
    cout<<b<<endl;

    dict.clear();
    dict.insert("leet");
    dict.insert("cod");
    s = "leetcode";
    b = solution.wordBreak(s, dict);
    cout<<b<<endl;

    dict.clear();
    dict.insert("aaaa");
    dict.insert("aaa");
    s = "aaaaaaa";
    b = solution.wordBreak(s, dict);
    cout<<b<<endl;

    dict.clear();
    dict.insert("aa");
    dict.insert("aaa");
    s = "aaaaaaa";
    b = solution.wordBreak(s, dict);
    cout<<b<<endl;

}
