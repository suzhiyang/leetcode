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
                if (i > si && c[i] == c[i - 1]) continue;
                if (sum + c[i] > target) break;
                cur.push_back(c[i]);
                dfs(r, cur, c, i + 1, sum + c[i], target);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
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
    int i, j;
    int a[] = {10,1,2,7,6,1,5};
    vector<int> v(a, a + 7);
//     int a[] = {1,1,2,2,5};
//     vector<int> v(a, a + 5);
    r = sol.combinationSum(v, 8);
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
