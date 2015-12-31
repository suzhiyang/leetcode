#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(vector<int> &r, vector<int> &v, int s, int e)
    {
        if (s == e) {r.push_back(v[s]); return;}
        for (int i = s + 1; i < e; i += 2)
        {
            vector<int> left, right;
            dfs(left, v, s, i - 1);
            dfs(right, v, i + 1, e);
            for (auto a : left)
                for (auto b : right)
                    if (v[i] == 1) r.push_back(a + b);
                    else if (v[i] == 2) r.push_back(a - b);
                    else r.push_back(a * b);
        }
    }
    
    vector<int> diffWaysToCompute(string s) {
        int i, n = 0;
        vector<int> v, r;
        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                v.push_back(n);
                n = 0;
                if (s[i] == '+') v.push_back(1);
                else if (s[i] == '-') v.push_back(2);
                else v.push_back(3);
            }
        }
        v.push_back(n);
        dfs(r, v, 0, v.size() - 1);
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> r;
    r = s.diffWaysToCompute("2-1-1");
    r = s.diffWaysToCompute("2*3-4*5");
    for (auto a : r)
        cout<<a<<",";
    cout<<endl;
}
