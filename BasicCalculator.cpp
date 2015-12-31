class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0, i, n = 0, sign = 1;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-')
            {
                cur = cur + sign * n;
                n = 0;
                if (s[i] == '+') sign = 1;
                else sign = -1;
            }
            else if (s[i] == '(')
            {
                n = 0;
                stk.push(cur); stk.push(sign);
                cur = 0; sign = 1;
            }
            else if (s[i] == ')')
            {
                cur = cur + sign * n;
                n = 0;
                int f = stk.top(), a;
                stk.pop();
                a = stk.top();
                stk.pop();
                cur = a + f * cur;
            }
        }
        cur = cur + sign * n;
        return cur;
    }
};
