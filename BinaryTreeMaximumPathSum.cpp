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
    int maxPathSum(TreeNode *root) {
        int maxacrossroot = INT_MIN;
        int pathsum = getmax(root, maxacrossroot);
        return max(pathsum, maxacrossroot);
    }

    int getmax(TreeNode *root, int &maxacrossroot)
    {
        if (root == NULL) return 0;
        int left, right, acrossroot;
        left = getmax(root->left, maxacrossroot);
        right = getmax(root->right, maxacrossroot);
        acrossroot = root->val;
        if (left > 0) acrossroot += left;
        if (right > 0) acrossroot += right;
        if (acrossroot > maxacrossroot) maxacrossroot = acrossroot;
        return max(root->val, max(root->val + left, root->val + right));
    }
};

int main()
{
    Solution s;
    //                       1
    //                     /   \
    //                    2     3
    //                   / \   / \
    //                  7   6 300 200
    //                 /
    //                8
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(300);
    root->right->right = new TreeNode(200);
    cout<<s.maxPathSum(root)<<endl;
    return 0;
}
