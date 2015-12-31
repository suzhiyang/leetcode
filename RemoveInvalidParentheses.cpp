#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(set<string> &res, string &cur, int l, int r,
             string &s, int pos, string &rem, int rpos)
    {
        if (r > l) return;
        if (pos == s.size())
        {
            if (rpos == rem.size())
                res.insert(cur);
//                res.push_back(cur);
            return;
        }
        string t = cur + s[pos];
        if (rpos < rem.size() && s[pos] == rem[rpos])
            dfs(res, cur, l, r, s, pos + 1, rem, rpos + 1);
        if (s[pos] == '(')
            dfs(res, t, l + 1, r, s, pos + 1, rem, rpos);
        else if (s[pos] == ')')
            dfs(res, t, l, r + 1, s, pos + 1, rem, rpos);
        else
            dfs(res, t, l, r, s, pos + 1, rem, rpos);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        stack<char> stk;
        int i;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') stk.push('(');
            else if (s[i] == ')')
            {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else stk.push(')');
            }
        }
        vector<string> res;
        set<string> h;
        string rem;
        while(!stk.empty())
        {
            rem += stk.top();
            stk.pop();
        }
        reverse(rem.begin(), rem.end());
        string cur;
        dfs(h, cur, 0, 0, s, 0, rem, 0);
        for (auto k: h)
            res.push_back(k);
        return res;
    }
};

int main()
{
    vector<string> r;
    r = Solution().removeInvalidParentheses("(a)())()");
    for (auto k : r)
        cout<<"#"<<k<<endl;
    r = Solution().removeInvalidParentheses(")(");
    for (auto k : r)
        cout<<"#"<<k<<endl;
    r = Solution().removeInvalidParentheses("))");
    for (auto k : r)
        cout<<"#"<<k<<endl;
    r = Solution().removeInvalidParentheses("((()");
    for (auto k : r)
        cout<<"#"<<k<<endl;
}
