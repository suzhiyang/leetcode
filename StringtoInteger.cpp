class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, r = 0, i, state = 0; // 0 - wait sign, 1 - wait num
        for (i = 0; i < str.size(); ++i)
        {
            if (str[i] == '+')
            {
                if (state == 0)
                {
                    sign = 1;
                    state = 1;
                }
                else return 0;
            }
            else if (str[i] == '-')
            {
                if (state == 0)
                {
                    sign = -1;
                    state = 1;
                }
                else return 0;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                if (state == 0) state = 1;
                if (r < INT_MAX / 10) r = r * 10 + str[i] - '0';
                else if (r == INT_MAX / 10)
                {
                    if (str[i] - '0' <= 7) r = r * 10 + str[i] - '0';
                    else if (sign == 1) return INT_MAX;
                    else if (sign == -1) return INT_MIN;
                }
                else if (sign == 1) return INT_MAX;
                else if (sign == -1) return INT_MIN;
            }
            else if (str[i] == ' ' && state == 0) continue;
            else break;
        }
        return r * sign;
    }
};
