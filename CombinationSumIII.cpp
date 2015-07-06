#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int k, int n, vector<int> &cur, vector<vector<int> > &r)
    {
        int i;
        if (cur.size() == k && n == 0)
        {
            r.push_back(cur);
        }
        else
        {
            int i, m = 1;
            if (cur.size() > 0) m = cur.back() + 1;
            for (i = m; i <= min(n, 9); ++i)
            {
                cur.push_back(i);
                dfs(k, n - i, cur, r);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > r;
        vector<int> cur;
        dfs(k, n, cur, r);
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > r = s.combinationSum3(3, 15);
    int i, j;
    for (i = 0; i < r.size(); ++i)
    {
        cout<<"[";
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<"]";
    }
    cout<<endl;
}
