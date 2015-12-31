class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp = root->right, *tail = root->left;
        if (tail != NULL)
        {
            root->right = root->left;
            root->left = NULL;
            while(tail->right != NULL)
                tail = tail->right;
            tail->right = tmp;
        }
    }
};
