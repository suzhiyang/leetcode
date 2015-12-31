class Solution {
public:
    int depth(TreeNode *root)
    {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (fabs(depth(root->left) - depth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
