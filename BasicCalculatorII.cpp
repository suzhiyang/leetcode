#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string infixtopostfix(string s)
    {
        stack<string> opstk;
        int i;
        string cur, str;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                cur += s[i];
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                string t;
                t += s[i];
                str += cur + " ";
                cur = "";
                if (opstk.empty())
                {
                    opstk.push(t);
                }
                else
                {
                    while (!opstk.empty())
                    {
                        str += opstk.top();
                        opstk.pop();
                    }
                    opstk.push(t);
                }
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                string t;
                t += s[i];
                str += cur + " ";
                cur = "";
                if (opstk.empty())
                {
                    opstk.push(t);
                }
                else
                {
                    while (!opstk.empty() && (opstk.top() == "*" || opstk.top() == "/"))
                    {
                        str += opstk.top();
                        opstk.pop();
                    }
                    opstk.push(t);
                }
            }
        }
        if (cur != "") str += cur + " ";
        while(!opstk.empty())
        {
            str += opstk.top();
            opstk.pop();
        }
        return str;
    }

    int postfixcalculator(string s)
    {
        int r = 0, i, cur = 0;
        stack<int> stk;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                cur = cur * 10 + s[i] - '0';
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                int a, b;
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                switch(s[i])
                {
                    case '+':
                        r = a + b;
                        break;
                    case '-':
                        r = b - a;
                        break;
                    case '*':
                        r = a * b;
                        break;
                    case '/':
                        r = b / a;
                }
                stk.push(r);
            }
            else if (s[i] == ' ')
            {
                stk.push(cur);
                cur = 0;
            }
        }
        return stk.top();
    }

    int calculate(string s) {
        string str = infixtopostfix(s);
        return postfixcalculator(str);
    }
};

int main()
{
    Solution s;
    string str = "1 + 2 * 3 - 4  ";
    cout<<s.calculate(str)<<endl;
}
