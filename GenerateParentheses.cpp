#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> m_r;
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, n, s);
        return m_r;
    }

    void generate(int l, int r, string &s)
    {
        if (l == 0 && r == 0)
        {
            m_r.push_back(s);
            return;
        }
        string s1, s2;
        if (l > 0)
        {
            s1 = s + '(';
            generate(l - 1, r, s1);
        }
        if (r > l)
        {
            s2 = s + ')';
            generate(l, r - 1, s2);
        }
    }
};

int main()
{
    Solution s;
    vector<string> r;
    r = s.generateParenthesis(4);
    int i;
    for(i = 0; i < r.size(); ++i)
        cout<<"\""<<r[i]<<"\",";
    cout<<endl;
}
