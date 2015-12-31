#include <iostream>
#include "ds.h"

class Solution {
private:
    int sum;
public:
    void dfs(TreeNode *root, int cur)
    {
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {sum += cur; return;}
        if (root->left != NULL) dfs(root->left, cur);
        if (root->right != NULL) dfs(root->right, cur);
    }
    
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};
