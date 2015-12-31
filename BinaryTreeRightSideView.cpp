class Solution {
public:
    void dfs(TreeNode *root, vector<int> &r, int level)
    {
        if (root == NULL) return;
        if (r.size() < level) r.push_back(root->val);
        dfs(root->right, r, level + 1);
        dfs(root->left, r, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        dfs(root, r, 1);
        return r;
    }
};
