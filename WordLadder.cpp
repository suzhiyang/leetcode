#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int l = 1, i, j;
        dict.insert(end);
        unordered_set<string>::iterator it;
        it = dict.find(start);
        if (it != dict.end()) dict.erase(it);
        queue<string> d;
        d.push(start);
        d.push("");
        while(!d.empty())
        {
            string cur = d.front();
            d.pop();
            if (cur == "")
            {
                ++l;
                if (!d.empty()) d.push("");
                continue;
            }
            for (i = 0; i < start.size(); ++i)
            {
                char t = cur[i];
                for (j = 0; j < 26; ++j)
                {
                    cur[i] = 'a' + j;
                    if (dict.find(cur) != dict.end())
                    {
                        if (cur == end) return l + 1;
                        d.push(cur);
                        dict.erase(cur);
                    }
                }
                cur[i] = t;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    unordered_set<string> dict;
//     dict.insert("hot");
//     dict.insert("cog");
//     dict.insert("dot");
//     dict.insert("dog");
//     dict.insert("hit");
//     dict.insert("lot");
//     dict.insert("log");
//     cout<<s.ladderLength("hit", "cog", dict)<<endl;

//    char d[][5] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
    char d[][4] = {"hot", "dog"};
    for (int i = 0; i < sizeof(d) / sizeof(d[0]); ++i)
        dict.insert(d[i]);
//    cout<<s.ladderLength("kiss", "tusk", dict)<<endl;
    cout<<s.ladderLength("hot", "dog", dict)<<endl;
}
