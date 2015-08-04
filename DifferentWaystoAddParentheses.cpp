#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> ways(vector<int> &v, int s, int e)
    {// op: -1: +, -2: -, -3: *
        vector<int> res;
        int p, op;
        if (s == e) 
        {
            res.push_back(v[s]);
            return res;
        }
        for (p = s + 1; p < e; p += 2)
        {
            vector<int> l, r;
            op = v[p];
            l = ways(v, s, p - 1);
            r = ways(v, p + 1, e);
            for (int i = 0; i < l.size(); ++i)
                for (int j = 0; j < r.size(); ++j)
                    if (op == -1) res.push_back(l[i] + r[j]);
                    else if (op == -2) res.push_back(l[i] - r[j]);
                    else if (op == -3) res.push_back(l[i] * r[j]);
        }
//         cout<<s<<"--"<<e<<"--------------"<<endl;
//         for (int i = 0; i < res.size(); ++i)
//             cout<<res[i]<<" ";
//         cout<<endl;
        return res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> tokens;
        int i, num = 0;
        for (i = 0; i < input.size(); ++i)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + input[i] - '0';
            }
            else
            {
                tokens.push_back(num);
                num = 0;
                if (input[i] == '+') tokens.push_back(-1);
                else if (input[i] == '-') tokens.push_back(-2);
                else if (input[i] == '*') tokens.push_back(-3);
            }
        }
        tokens.push_back(num);
//         for (i = 0; i < tokens.size(); ++i)
//             cout<<tokens[i]<<" ";
//         cout<<endl;
        return ways(tokens, 0, tokens.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<int> r;
    string str;
    str = "2*3-4*5";
    r = s.diffWaysToCompute(str);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<",";
    cout<<endl;
}
