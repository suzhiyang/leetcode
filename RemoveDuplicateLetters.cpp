#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        int i, h[26] = {0}, e[26] = {0};
        for (i = 0; i < s.size(); ++i)
            ++h[s[i] - 'a'];
        for (i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (e[c - 'a'] == 0 && !stk.empty() && c < stk.top())
            {
                while(!stk.empty())
                {
                    if (c < stk.top() && h[stk.top() - 'a'] > 0)
                    {
                        --e[stk.top() - 'a'];
                        stk.pop();
                    }
                    else break;
                }
            }
            if (e[c - 'a'] == 0)
            {
                stk.push(c);
                ++e[c - 'a'];
            }
            --h[c - 'a'];
        }
        string r;
        while(!stk.empty())
        {
            r = stk.top() + r;
            stk.pop();
        }
        return r;
    }
};

int main()
{
    string str;
    str = "bcabc";
    cout<<str<<" "<<Solution().removeDuplicateLetters(str)<<endl;
    str = "bcabca";
    cout<<str<<" "<<Solution().removeDuplicateLetters(str)<<endl;
    str = "cbacdcbc";
    cout<<str<<" "<<Solution().removeDuplicateLetters(str)<<endl;
    str = "abacb";
    cout<<str<<" "<<Solution().removeDuplicateLetters(str)<<endl;
}
