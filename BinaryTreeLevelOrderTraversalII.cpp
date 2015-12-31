class Solution {
public:
    void dfs(vector<vector<int> > &r, int level, TreeNode *root)
    {
        if (root == NULL) return;
        vector<int> cur;
        if (r.size() < level) r.push_back(cur);
        r[level - 1].push_back(root->val);
        dfs(r, level + 1, root->left);
        dfs(r, level + 1, root->right);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > r;
        dfs(r, 1, root);
        reverse(r.begin(), r.end());
        return r;
    }
};
