#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0, i, j, start = 0;
        int dict[300];
        for (i = 0; i < 300; ++i)
            dict[i] = -1;
        for (i = 0; i < s.size(); ++i)
        {
            if (dict[s[i]] == -1)
                dict[s[i]] = i;
            else
            {
                if (i - start > m) m = i - start;
                for (j = start; j < dict[s[i]]; ++j)
                    dict[s[j]] = -1;
                start = dict[s[i]] + 1;
                dict[s[i]] = i;
            }
        }
        if (i - start > m) m = i - start;
        return m;
    }
};

int main()
{
    Solution s;
    string str;
    str = "abcabcbb";
    cout<<str<<":"<<s.lengthOfLongestSubstring(str)<<endl;
    str = "b";
    cout<<str<<":"<<s.lengthOfLongestSubstring(str)<<endl;
    str = "abbbcde";
    cout<<str<<":"<<s.lengthOfLongestSubstring(str)<<endl;
    str = "acdvda";
    cout<<str<<":"<<s.lengthOfLongestSubstring(str)<<endl;
    str = "dcdvcuyda";
    cout<<str<<":"<<s.lengthOfLongestSubstring(str)<<endl;
}
