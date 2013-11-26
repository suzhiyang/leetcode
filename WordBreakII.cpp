#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
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
                it = dict.find(sub);
                if (it != dict.end() && seg[j] == 1)
                {
                    seg[i] = 1;
                    break;
                }
            }
        }
//         cout<<s<<endl;
//         for (i = 1; i <= len; ++i)
//             cout<<seg[i];
//         cout<<endl;
        vector<string> result = possiblesentences(seg, s, dict, len);
        return result;
    }

    vector<string> possiblesentences(vector<int> &seg, string &s, unordered_set<string> &dict, int len)
    {
        int i, j;
        vector<string> result;
        if (len == 0)
        {
            result.push_back("");
            return result;
        }
        for (i = len - 1; i >= 0; --i)
        {
            if (seg[i] == 0) continue;
            string str = s.substr(i, len - i);
//            cout<<"*["<<i<<","<<len<<"] "<<str<<endl;                
            if (dict.find(str) != dict.end())
            {
                string suffix;
                if (i != 0) suffix = " " + str;
                else suffix = str;
                vector<string> temp;
                temp = possiblesentences(seg, s, dict, i);
                vector<string>::iterator it;
                for (it = temp.begin(); it != temp.end(); ++it)
                {
                    result.push_back(*it + suffix);
                }
            }
        }
        return result;
    }
};

int main()
{
    unordered_set<string> dict;
    string str("catsanddog");
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    Solution s;
    vector<string> result;
    result = s.wordBreak(str, dict);
    for (vector<string>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<endl;
    }
}
