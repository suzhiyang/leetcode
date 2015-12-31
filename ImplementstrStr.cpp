#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        if (haystack.size() < needle.size()) return -1;
        for (i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            for (j = 0; j < needle.size(); ++j)
                if (haystack[i + j] != needle[j]) break;
            if (j == needle.size()) return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("aaa","aaaa")<<endl;
    cout<<s.strStr("","")<<endl;
    cout<<s.strStr("a","a")<<endl;
}
