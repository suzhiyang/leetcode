#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int val1, val2, t, i;
        stack<string> s;
        for (i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-"
                || tokens[i] == "*" || tokens[i] == "/")
            {
                val2 = atoi(s.top().c_str());
                s.pop();
                val1 = atoi(s.top().c_str());
                s.pop();
                if (tokens[i] == "+") t = val1 + val2;
                else if (tokens[i] == "-") t = val1 - val2;
                else if (tokens[i] == "*") t = val1 * val2;
                else if (tokens[i] == "/") t = val1 / val2;
                stringstream ss;
                ss<<t;
                s.push(ss.str());
            }
            else s.push(tokens[i]);
        }
        return atoi(s.top().c_str());
    }
};

int main()
{
    Solution s;
    vector<string> tokens;
    // ["2", "1", "+", "3", "*"], 9
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("*");
    cout<<s.evalRPN(tokens)<<endl;
    tokens.clear();

    // ["4", "13", "5", "/", "+"], 6
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    cout<<s.evalRPN(tokens)<<endl;
    tokens.clear();

    // 5 1 2 + 4 * + 3 -, 14
    tokens.push_back("5");
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("+");
    tokens.push_back("4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("-");
    cout<<s.evalRPN(tokens)<<endl;
    tokens.clear();
}
