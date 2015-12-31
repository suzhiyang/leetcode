#include <iostream>
#include "ds.h"

// class Solution {
// public:
//     bool dfs(TreeNode *root, int l, int h)
//     {
//         if (root == NULL) return true;
//         if (root->val <= l || root->val >= h) return false;
//         return dfs(root->left, l, root->val) && dfs(root->right, root->val, h);
//     }

//     bool isValidBST(TreeNode* root) {
//         if (root == NULL) return true;
//         return dfs(root->left, INT_MIN, root->val) &&
//             dfs(root->right, root->val, INT_MAX);
//     }
// };
class Solution {
public:
    bool inorder(TreeNode **prev, TreeNode *cur)
    {
        if (cur == NULL) return true;
        if (inorder(prev, cur->left) == false) return false;
        if (*prev != NULL && (*prev)->val >= cur->val) return false;
        *prev = cur;
        if (inorder(prev, cur->right) == false) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return inorder(&prev, root);
    }
};

int main()
{
}
