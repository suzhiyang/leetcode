class Solution {
public:
    int depth(TreeNode *root, int d)
    {
        if (root == NULL) return d;
        return max(depth(root->left, d + 1), depth(root->right, d + 1));
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(depth(root->left, 1), depth(root->right, 1));
    }
};
