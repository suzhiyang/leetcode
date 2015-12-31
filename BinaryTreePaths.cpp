class Solution {
public:
    void dfs(vector<string> &r, string cur, TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL) r.push_back(cur + to_string(root->val));
        if (root->left != NULL) dfs(r, cur + to_string(root->val) + "->", root->left);
        if (root->right != NULL) dfs(r, cur + to_string(root->val) + "->", root->right);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> r;
        if (root != NULL) dfs(r, "", root);
        return r;
    }
};
