#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool ispalindrome(string &s, int i, int j, vector<vector<int> > &p)
    {
        if (p[i][j] >= 0) return p[i][j];
        if (i == j) p[i][j] = 1;
        else if (i == j - 1)
        {
            if (s[i] == s[j]) p[i][j] = 1;
            else p[i][j] = 0;
        }
        else
        {
            p[i][j] = s[i] == s[j] && ispalindrome(s, i + 1, j - 1, p);
        }
        return p[i][j];
    }

    void dfs(vector<vector<string> > &r, vector<string> &cur, string &s, int pos,
             vector<vector<int> > &p)
    {
        if (pos == s.size())
        {
            r.push_back(cur);
        }
        else
        {
            for (int i = pos; i < s.size(); ++i)
            {
                if (ispalindrome(s, pos, i, p))
                {
                    cur.push_back(s.substr(pos, i - pos + 1));
                    dfs(r, cur, s, i + 1, p);
                    cur.pop_back();
                }
            }
        }
    }
    
    vector<vector<string> > partition(string s) {
        vector<vector<int> > p(s.size(), vector<int>(s.size(), -1));
        vector<vector<string> > r;
        vector<string> cur;
        dfs(r, cur, s, 0, p);
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > r;
    r = s.partition("aaaab");
    for (auto i : r)
    {
        for (auto k : i)
            cout<<k<<",";
        cout<<endl;
    }
}
