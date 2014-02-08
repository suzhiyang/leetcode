#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int> > charstack;
        int max = 0, i, startpos = 0, t;
        for (i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case '(':
                    charstack.push(make_pair('(', i));
                    break;
                case ')':
                    if (charstack.empty())
                        startpos = i + 1;
                    else
                    {
                        pair<char, int> temp = charstack.top();
                        charstack.pop();
                        if (!charstack.empty())
                            t = i - charstack.top().second;
                        else
                            t = i - startpos + 1;
                        if (t > max) max = t;
                    }
            }
        }
        return max;
    }
};

int main()
{
    string str = "(()";
    Solution s;
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
    str = ")()())";
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
    str = ")()())()(())";
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
    str = "))";
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
    str = "";
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
    str = "()()(()(";
    cout<<str<<" : "<<s.longestValidParentheses(str)<<endl;
}
