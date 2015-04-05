#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string> > m_r;
public:
    vector<vector<string> > partition(string s) {
        m_r.clear();
        vector<string> output;
        dfs(s, 0, output);
        return m_r;
    }

    void dfs(string &s, int start, vector<string> &output)
    {
        if (start == s.size())
        {
            m_r.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            if (ispalindrome(s, start, i))
            {
                output.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, output);
                output.pop_back();
            }
        }
    }

    bool ispalindrome(string &s, int a, int b)
    {
        int i = a, j = b;
        while(i < j)
        {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int i, j;
    string a = "aaab";
    vector<vector<string> > r = s.partition(a);
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
        {
            cout<<"\""<<r[i][j]<<"\"";
        }
        cout<<endl;
    }
}
    
