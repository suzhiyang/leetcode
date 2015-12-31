#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > r;
    vector<int> cur, v;
    
    void dfs(vector<int> &nums)
    {
        int i, j;
        if (cur.size() == nums.size())
        {
            r.push_back(cur);
            // vector<int> t(cur.size());
            // for (i = 0; i < cur.size(); ++i)
            //     t[i] = nums[cur[i]];
            // r.push_back(t);
        }
        else
        {
            for (i = 0; i < nums.size(); ++i)
            {
                if (v[i] == 0)
                {
                    // if (cur.size() > 0)
                    // {
                    //     for (j = cur.size() - 1; j >= 0; --j)
                    //         if (nums[cur[j]] == nums[i] && i < cur[j]) break;
                    //     if (j >= 0) continue;
                    // }
                    // cur.push_back(i);
                    if (i > 0 && nums[i] == nums[i - 1] && v[i - 1]) continue;
                    cur.push_back(nums[i]);
                    v[i] = 1;
                    dfs(nums);
                    cur.pop_back();
                    v[i] = 0;
                }
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        v.assign(nums.size(), 0);
        dfs(nums);
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > r;
    int a[] = {1,1,1,2};
    int i, j;
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    r = s.permuteUnique(v);
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
