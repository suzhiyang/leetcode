class Solution {
public:
    int count(TreeNode *root)
    {
        if (root == NULL) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int l;
        l = count(root->left);
        if (k == l + 1) return root->val;
        else if (k < l + 1) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - l - 1);
    }
};
