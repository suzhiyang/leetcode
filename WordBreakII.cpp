#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void dfs(vector<string> &r, string cur, string &s, int pos, unordered_set<string> &dict)
{
    if (pos == s.size())
    {
        if (cur.back() == ' ') cur.pop_back();
        r.push_back(cur);
    }
    else
    {
        int i;
        for (i = pos; i < s.size(); ++i)
        {
            string t = s.substr(pos, i - pos + 1);
            if (dict.find(t) != dict.end())
            {
                cur += t + " ";
                dfs(r, cur, s, i + 1, dict);
            }
        }
    }
}

class Solution {
public:
    void dfs(vector<string> &r, string cur, vector<vector<int> > &mark, string &s, int idx)
    {
        if (idx == 0)
        {
            r.push_back(cur);
        }
        else
        {
            for (auto j: mark[idx])
            {
                string t = s.substr(j, idx - j);
                if (cur != "") t += " ";
                dfs(r, t + cur, mark, s, j);
            }
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        vector<int> dp(s.size() + 1, 0);
        vector<vector<int> > mark(s.size() + 1);
        vector<string> r;
        int i, j;
        dp[0] = 1;
        for (i = 1; i <= s.size(); ++i)
        {
            for (j = 0; j < i; ++j)
            {
                if (dp[j])
                {
                    string t = s.substr(j, i - j);
                    if (dict.find(t) != dict.end())
                    {
                        dp[i] = 1;
                        mark[i].push_back(j);
                    }
                }
            }
        }
        dfs(r, "", mark, s, s.size());
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> r;
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("aa");
    r = s.wordBreak("aaaa", dict);
    for (auto k : r)
        cout<<k<<",";
    cout<<endl;
}
