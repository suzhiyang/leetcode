#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int> > r;
    int m_target;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
                dfs(candidates, i + 1, sum, cur);
                cur.pop_back();
                sum -= candidates[i];
                while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                    ++i;
            }
        }
    }
};

int main()
{
    Solution s;
    int a[] = {10,1,2,7,6,1,5};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    vector<vector<int> > r;
    r = s.combinationSum2(v, 8);
    int i, j;
    for(i = 0; i < r.size(); ++i)
    {
        for(j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
