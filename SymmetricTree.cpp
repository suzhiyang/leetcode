// class Solution {
// public:
//     bool symmetric(TreeNode *l, TreeNode *r)
//     {
//         if (l == NULL && r == NULL) return true;
//         else if ((l == NULL && r != NULL) || (l != NULL && r == NULL)) return false;
//         if (l->val != r->val) return false;
//         return symmetric(l->left, r->right) && symmetric(l->right, r->left);
//     }
    
//     bool isSymmetric(TreeNode* root) {
//         if (root == NULL) return true;
//         return symmetric(root->left, root->right);
//     }
// };


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode *> q1, q2;
        q1.push(root->left); q2.push(root->right);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *t1 = q1.front(), *t2 = q2.front();
            q1.pop(); q2.pop();
            if (t1 == NULL && t2 == NULL) continue;
            else if (t1 == NULL && t2 != NULL) return false;
            else if (t1 != NULL && t2 == NULL) return false;
            else if (t1->val != t2->val) return false;
            q1.push(t1->left); q1.push(t1->right);
            q2.push(t2->right); q2.push(t2->left);
        }
        if (q1.empty() && q2.empty()) return true;
        return false;
    }
};
