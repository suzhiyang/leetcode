class Solution {
public:
    int count(TreeNode *root, bool left)
    {
        int r = 0;
        while(root != NULL)
        {
            if (left) root = root->left;
            else root = root->right;
            ++r;
        }
        return r;
    }

    int countNodes(TreeNode* root) {
        int l, r;
        l = count(root, true);
        r = count(root, false);
        if (l == r) return (1<<l) - 1;
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
