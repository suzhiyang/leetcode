#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = words[0].size(), i, j, cnt = 0, pos, startpos;
        vector<int> r;
        if (s.size() < l * words.size()) return r;
        map<string, int> h, w;
        for (i = 0; i < words.size(); ++i)
            ++h[words[i]];
        for (i = 0; i <= s.size() - l;)
        {
            if (cnt == 0) startpos = i;
            string cur = s.substr(i, l);
            if (h.find(cur) != h.end())
            {
                ++w[cur]; ++cnt;
                while (w[cur] > h[cur])
                {
                    pos = i - (cnt - 1) * l;
                    string t = s.substr(pos, l);
                    --w[t]; --cnt;
                }
                if (cnt == words.size())
                {
                    pos = i - l * (cnt - 1);
                    r.push_back(pos);
                    i = pos + 1;
                    cnt = 0; w.clear();
                }
                else i += l;
            }
            else
            {
                i = startpos + 1;
                cnt = 0; w.clear();
            }
        }
        return r;
    }
};

// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int l = words[0].size(), i, j;
//         vector<int> r;
//         map<string, int> h, w;
//         if (s.size() < l * words.size()) return r;
//         for (i = 0; i < words.size(); ++i)
//             ++h[words[i]];
//         for (i = 0; i <= s.size() - l * words.size(); ++i)
//         {
//             w.clear();
//             for (j = 0; j < words.size(); ++j)
//             {
//                 string cur = s.substr(i + j * l, l);
//                 if (h.find(cur) != h.end())
//                 {
//                     ++w[cur];
//                     if (w[cur] > h[cur]) break;
//                 }
//                 else break;
//             }
//             if (j == words.size()) r.push_back(i);
//         }
//         return r;
//     }
// };

int main()
{
    string str;
    Solution s;
    vector<string> words(1, "foo");
    words.push_back("bar");
    str = "barfoothefoobarman";
    vector<int> r = s.findSubstring(str, words);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;
    
    words.push_back("bar");
    str = "barfoothefoobarbarman";
    r = s.findSubstring(str, words);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;
    
    words.push_back("kkk");
    str = "fookkkkkkbarbarfoobarkkkman";
    r = s.findSubstring(str, words);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;

    words.clear();
    words.assign(2, "a");
    str = "aaa";
    r = s.findSubstring(str, words);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;

    words.clear();
    words.assign(2, "ba");
    words.push_back("ab");
    str = "ababaab";
    r = s.findSubstring(str, words);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;
}
