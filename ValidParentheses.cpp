class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if (stk.empty()) return false;
                char t = stk.top();
                stk.pop();
                switch(s[i])
                {
                    case ')':
                        if (t != '(') return false;
                        break;
                    case ']':
                        if (t != '[') return false;
                        break;
                    case '}':
                        if (t != '{') return false;
                }
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
};
