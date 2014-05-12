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
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int r = balanced(root);
        if (r == -1) return false;
        return true;
    }

    int balanced(TreeNode *root)
    {
        if (root == NULL) return 0;
        int left, right, depth;
        left = balanced(root->left);
        if (left == -1) return -1;
        right = balanced(root->right);
        if (right == -1) return -1;
        if (left - right > 1 || right - left > 1)
            return -1;
        return max(left, right) + 1;
    }
};

int main()
{
    Solution s;
    //                       1
    //                     /   \
    //                    2     3
    //                   / \   / \
    //                  4   5 6   7
    //                 /
    //                8
    //                 \
    //                  9
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(8);
//    root->left->left->left->right = new TreeNode(9);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<s.isBalanced(root)<<endl;
    return 0;
}
