#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int tobits(const string &s)
    {   // A:00, C:01, G:10, T:11
        int i, r = 0;
        map<char, int> m;
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        for(i = 0; i < s.size(); ++i)
            r = (r | m[s[i]]) << 2;
        return r;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;
        string str;
        int i, b;
        map<int, int> hash;
        map<int, int>::iterator it;
        for (i = 0; i < int(s.size()) - 9; ++i)
        {
            str = s.substr(i, 10);
            b = tobits(str);
            ++hash[b];
            if (hash[b] == 2) r.push_back(str);
        }
        return r;
    }
};

int main()
{
    Solution s;    
    string str;
    str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
//    str = "AAAAACCCCC";
    str = "AAAAAAAAAAA";
    vector<string> r = s.findRepeatedDnaSequences(str);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
}
