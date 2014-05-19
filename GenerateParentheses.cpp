#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        if (n == 1)
        {
            r.push_back("()");
            return r;
        }
        else if (n == 2)
        {
            vector<string> r;
            r.push_back("(())");
            r.push_back("()()");
            return r;
        }
        r = generateParenthesis(n - 1);
        r.reserve(r.size() * 3);
        vector<string> v;
        int i;
        for(i = 0; i < r.size(); ++i)
        {
            string lstr = "()" + r[i], rstr = r[i] + "()";
            r[i] = "(" + r[i] + ")";
            v.push_back(lstr);
            if (lstr != rstr) v.push_back(rstr);
        }
        r.insert(r.end(), v.begin(), v.end());
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> r;
    r = s.generateParenthesis(3);
    int i;
    for(i = 0; i < r.size(); ++i)
        cout<<"\""<<r[i]<<"\",";
    cout<<endl;
}
