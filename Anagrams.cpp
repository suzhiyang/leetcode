#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<int> > h;
        map<string, vector<int> >::iterator it;
        int i, j, a[26];
        for (i = 0; i < strs.size(); ++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            it = h.find(t);
            if (it == h.end())
                h.insert(make_pair(t, vector<int>(1, i)));
            else it->second.push_back(i);
        }
        vector<string> result;
        for (it = h.begin(); it != h.end(); ++it)
        {
            if (it->second.size() > 1)
                for (i = 0; i < it->second.size(); ++i)
                    result.push_back(strs[it->second[i]]);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs, r;
    strs.push_back("abc");
    strs.push_back("abcd");
    strs.push_back("bca");
    strs.push_back("bac");
    r = s.anagrams(strs);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
}
