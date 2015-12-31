class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &cur, int n, int k, int pos)
    {
        if (cur.size() == k)
            r.push_back(cur);
        else
        {
            int i;
            for (i = pos; i <= n; ++i)
            {
                cur.push_back(i);
                dfs(r, cur, n, k, i + 1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> cur;
        dfs(r, cur, n, k, 1); //1,2,...n
        return r;
    }
};
