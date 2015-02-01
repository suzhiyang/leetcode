#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int> > r;
    int m_target;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        r.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        m_target = target;
        int sum = 0;
        dfs(candidates, 0, sum, cur);
        return r;
    }

    void dfs(vector<int> &candidates, int pos, int sum, vector<int> &cur)
    {
        int i;
        if (sum > m_target) return;
        else if (sum == m_target) r.push_back(cur);
        else
        {
            for(i = pos; i < candidates.size(); ++i)
            {
                sum += candidates[i];
                cur.push_back(candidates[i]);
                dfs(candidates, i, sum, cur);
                cur.pop_back();
                sum -= candidates[i];
            }
        }
    }
};

int main()
{
    Solution s;
    int a[] = {2,3,6,7};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    vector<vector<int> > r;
    r = s.combinationSum(v, 7);
    int i, j;
    for(i = 0; i < r.size(); ++i)
    {
        for(j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
