#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasSum(TreeNode *root, int sum, int currentsum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val + currentsum) return true;
            else return false;
        }
        bool rl = false, rr = false;
        if (root->left != NULL) rl = hasSum(root->left, sum, root->val + currentsum);
        if (root->right != NULL) rr = hasSum(root->right, sum, root->val + currentsum);
        return rl || rr;

    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return hasSum(root, sum, 0);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout<<s.hasPathSum(root, 21)<<endl;
    cout<<s.hasPathSum(root, 22)<<endl;
    return 0;
}
