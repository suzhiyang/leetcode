class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *t = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(t);
        return root;
    }
};
