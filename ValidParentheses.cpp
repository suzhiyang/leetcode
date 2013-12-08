#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charstack;
        int i;
        for(i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    charstack.push(s[i]);
                    break;
                case ')':
                    if (charstack.size() == 0) return false;
                    if (charstack.top() == '(')
                        charstack.pop();
                    else return false;
                    break;
                case ']':
                    if (charstack.size() == 0) return false;
                    if (charstack.top() == '[')
                        charstack.pop();
                    else return false;
                    break;
                case '}':
                    if (charstack.size() == 0) return false;
                    if (charstack.top() == '{')
                        charstack.pop();
                    else return false;
                    break;
            }
        }
        if (charstack.size() == 0) return true;
        return false;
    }
};

int main()
{
}
