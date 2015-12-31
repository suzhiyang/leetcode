class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0, i, n = 0, a, t, sign;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (!stk.empty() && stk.top() < -2)
                {
                    t = stk.top(); stk.pop();
                    a = stk.top(); stk.pop();
                    if (t == -3) n = a * n;
                    else n = a / n;
                }
                stk.push(n);
                n = 0;
                if (s[i] == '+') stk.push(-1);
                else if (s[i] == '-') stk.push(-2);
                else if (s[i] == '*') stk.push(-3);
                else stk.push(-4);
            }
        }
        if (!stk.empty() && stk.top() < -2)
        {
            t = stk.top(); stk.pop();
            a = stk.top(); stk.pop();
            if (t == -3) n = a * n;
            else n = a / n;
        }
        while(!stk.empty())
        {
            t = stk.top(); stk.pop();
            sign = (t == -1)? 1: -1;
            cur = cur + sign * n;
            if (!stk.empty())
            {
                n = stk.top(); stk.pop();
            }
        }
        cur += n;
        return cur;
    }
};
