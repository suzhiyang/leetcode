#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > r;
    vector<vector<int> > combine(int n, int k) {
        int i;
        vector<int> c;
        r.clear();
        dfs(n, k, 1, c);
        return r;
    }

    void dfs(int n, int k, int pos, vector<int> &c)
    {
        if (k == c.size())
        {
            r.push_back(c);
            return;
        }
        int i;
        for(i = pos; i <= n; ++i)
        {
            c.push_back(i);
            dfs(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > r = s.combine(4, 3);
    int i, j;
    for(i = 0; i < r.size(); ++i)
    {
        for(j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
