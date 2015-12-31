class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q),
            *r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        else if (l) return l;
        else return r;
    }
};

// class Solution {
// public:
//     bool dfs(vector<TreeNode *> &p, TreeNode *root, TreeNode *n)
//     {
//         if (root == NULL) return false;
//         p.push_back(root);
//         if (root == n) return true;
//         if (dfs(p, root->left, n)) return true;
//         if (dfs(p, root->right, n)) return true;
//         p.pop_back();
//         return false;
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode *> vp, vq;
//         dfs(vp, root, p);
//         dfs(vq, root, q);
//         int i;
//         for (i = 1; i < vp.size() && i < vq.size(); ++i)
//             if (vp[i] != vq[i]) break;
//         return vp[i - 1];
//     }
// };
