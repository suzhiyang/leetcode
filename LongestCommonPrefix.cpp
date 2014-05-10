#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string prefix;
        int p = 0;
        while(1)
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (!(p < strs[i].size() && p < strs[0].size() && strs[i][p] == strs[0][p]))
                    return prefix;
            }
            prefix += strs[0][p];
            ++p;
        }
        return prefix;
    }
};

int main()
{
    vector<string> v;
    v.push_back("abc");
//    v.push_back("abdkkjk");
//    v.push_back("ab");
    Solution s;
    cout<<s.longestCommonPrefix(v)<<endl;
}
