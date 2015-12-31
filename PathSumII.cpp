class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &cur, TreeNode *root, int sum)
    {
        if (root == NULL) return;
        cur.push_back(root->val);
        if (root->val == sum && root->left == NULL && root->right == NULL)
            r.push_back(cur);
        dfs(r, cur, root->left, sum - root->val);
        dfs(r, cur, root->right, sum - root->val);
        cur.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > r;
        vector<int> cur;
        dfs(r, cur, root, sum);
        return r;
    }
};
