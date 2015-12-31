#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int i;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') stk.push(i);
            else
            {
                if (!stk.empty() && s[stk.top()] == '(') stk.pop();
                else stk.push(i);
            }
        }
        int r = 0, cur;
        if (stk.empty()) r = s.size();
        else
        {
            cur = stk.top(); stk.pop();
            r = max(r, int(s.size() - cur - 1));
            while(!stk.empty())
            {
                r = max(r, cur - stk.top() - 1);
                cur = stk.top(); stk.pop();
            }
            r = max(r, cur);
        }
        return r;
    }
};

int main()
{
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses("(()")<<endl;
}
