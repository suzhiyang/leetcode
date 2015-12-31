class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &cur, vector<int> &nums)
    {
        int i, j;
        if (cur.size() == nums.size())
            r.push_back(cur);
        else
        {
            for (i = 0; i < nums.size(); ++i)
            {
                for (j = 0; j < cur.size(); ++j)
                    if (nums[i] == cur[j]) break;
                if (j < cur.size()) continue;
                cur.push_back(nums[i]);
                dfs(r, cur, nums);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > r;
        vector<int> cur;
        dfs(r, cur, nums);
        return r;
    }
};
