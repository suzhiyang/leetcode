#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int i, r, a, b;
        for (i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                b = stk.top(); stk.pop();
                a = stk.top(); stk.pop();
                if (tokens[i] == "+") r = a + b;
                else if (tokens[i] == "-") r = a - b;
                else if (tokens[i] == "*") r = a * b;
                else if (tokens[i] == "/") r = a / b;
                stk.push(r);
            }
            else stk.push(atoi(tokens[i].c_str()));
        }
        return stk.top();
    }
};

int main()
{
}
