#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> r;
        int len = L[0].size();
        int i, j, k, c = 0;
        string s1, s2;
        map<string, int> dict, hash;
        map<string, int>::iterator it1, it2;
        for (i = 0; i < L.size(); ++i)
            ++dict[L[i]];
        for(k = 0; k < len; ++k)
        {
            for (i = k; i < S.size() - len + 1; i += len)
            {
                s1 = S.substr(i, len);
//                cout<<"#"<<s1<<","<<i<<","<<c<<endl;
                it1 = dict.find(s1);
                if (it1 != dict.end())
                {
                    ++hash[s1];
                    if (hash[s1] <= dict[s1]) ++c;
                    else
                    {
                        for (j = i - c * len; j < i; j += len)
                        {
                            s2 = S.substr(j, len);
                            --hash[s2];
                            if (s1 == s2) break;
                            --c;
                        }
                    }
                    if (c == L.size())
                        r.push_back(i - (c - 1) * len);
                }
                else {c = 0; hash.clear();}
            }
            c = 0; hash.clear();
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> L;
//     string S = "barfoobarbarfoothefoobarman";
//     L.push_back("foo");
//     L.push_back("bar");
    string S = "barfoothefoobarman";
    L.push_back("foo");
    L.push_back("bar");
//     string S = "aaaaaaaa";
//     L.push_back("aa");
//     L.push_back("aa");
//     L.push_back("aa");
    vector<int> r = s.findSubstring(S, L);
    int i;
    for (i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;
}
