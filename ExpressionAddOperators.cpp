#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "ds.h"
using namespace std;

class Solution {
public:
    void dfs(vector<string> &r, string expr, string &num, int pos, long long cur, long long n, int target)
    {
        if (pos == num.size())
        {
            if (cur + n == target)
                r.push_back(expr);
        }
        else
        {
            long long t = n;
            n = 0;
            for (int i = pos; i < num.size(); ++i)
            {
                n = n * 10 + num[i] - '0';
                string strn = to_string(n);
                dfs(r, expr + "+" + strn, num, i + 1, cur + t, n, target);
                dfs(r, expr + "-" + strn, num, i + 1, cur + t, -n, target);
                dfs(r, expr + "*" + strn, num, i + 1, cur, t * n, target);
                if (num[pos] == '0') break;
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> r;
        long long n = 0, i;
        for (i = 0; i < num.size(); ++i)
        {
            n = n * 10 + num[i] - '0';
            dfs(r, to_string(n), num, i + 1, 0, n, target);
            if (num[0] == '0') break;
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> r;
    r = s.addOperators("105", 5);
//    r = s.addOperators("123", 6);
    r = s.addOperators("00", 0);
//    r = s.addOperators("232", 8);
//    r = s.addOperators("1005", 95);
    for (auto a : r)
        cout<<a<<endl;
}
