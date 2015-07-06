class Solution {
public:
    int traverse(TreeNode *root, int &c)
    {
        if (root == NULL) return INT_MAX;
        int l, r;
        l = traverse(root->left, c);
        if (c == 0) return l;
        if (--c == 0) return root->val;
        r = traverse(root->right, c);
        return r;
    }
    
    int kthSmallest(TreeNode *root, int k) {
        return traverse(root, k);
    }
};
