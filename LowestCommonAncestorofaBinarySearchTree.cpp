class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *t = root;
        while(true)
        {
            if (p->val > t->val && q->val > t->val) t = t->right;
            else if (p->val < t->val && q->val < t->val) t= t->left;
            else return t;
        }
    }
};
