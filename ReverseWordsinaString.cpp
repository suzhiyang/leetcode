#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s == "") return;
        int i = 0, j, pos = 0;
        while(i < s.size() && s[i] == ' ') ++i;
        while(i < s.size())
        {
            while(i < s.size() && s[i] != ' ') s[pos++] = s[i++];
            j = i;
            while(i < s.size() && s[i] == ' ') ++i;
            if (i < s.size() && i > j) s[pos++] = ' ';
        }
        s.resize(pos);
        i = 0;
        while(i < s.size())
        {
            j = i;
            while(j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }
};

int main()
{
    string str = " ";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
    str = "1 ";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
    str = "        a     b     ";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
    str = "        abc     ";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
    str = "acc";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
    str = "hello world!";
    Solution().reverseWords(str);
    cout<<"#"<<str<<"#"<<endl;
}
