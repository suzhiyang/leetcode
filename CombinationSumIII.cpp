#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &cur, int sum, int k, int n)
    {
        if (cur.size() == k)
        {
            if (sum == n) r.push_back(cur);
        }
        else
        {
            int i = (cur.size() == 0)? 1:(cur.back() + 1);
            for (; i <= 9; ++i)
            {
                if (sum + i > n) break;
                cur.push_back(i);
                dfs(r, cur, sum + i, k, n);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > r;
        vector<int> cur;
        dfs(r, cur, 0, k, n);
        return r;
    }
};


int main()
{
    Solution sol;
    vector<vector<int> > r;
    int i, j;
    r = sol.combinationSum3(3, 9);
    r = sol.combinationSum3(3, 7);
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
