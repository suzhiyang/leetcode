class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int d = INT_MAX;
        if (root->left) d = minDepth(root->left);
        if (root->right) d = min(d, minDepth(root->right));
        if (d == INT_MAX) d = 0;
        return d + 1;
    }
};
