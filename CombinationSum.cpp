#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &cur, vector<int> &c, int si, int sum, int target)
    {
        if (sum == target)
            r.push_back(cur);
        else if (sum < target)
        {
            int i;
            for (i = si; i < c.size(); ++i)
            {
                cur.push_back(c[i]);
                dfs(r, cur, c, i, sum + c[i], target);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > r;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(r, cur, candidates, 0, 0, target);
        return r;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > r;
    int a[] = {2,3,6,7}, i, j;
    vector<int> v(a, a + 4);
    r = sol.combinationSum(v, 7);
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
