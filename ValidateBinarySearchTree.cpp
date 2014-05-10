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
private:
    int m_min, m_max;
public:
    bool validate(TreeNode *root, int min, int max)
    {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        m_max = 99999;
        m_min = -99999;
        return validate(root, m_min, m_max);
    }
};

int main()
{
    /*              5
     *             / \
     *            3   7
     *           / \
     *          1   8 (4)
     */
    TreeNode *t[5];
    t[0] = new TreeNode(5);
    t[1] = new TreeNode(3);
    t[2] = new TreeNode(7);
    t[3] = new TreeNode(1);
    t[4] = new TreeNode(8);
    t[0]->left = t[1];
    t[0]->right = t[2];
    t[1]->left = t[3];
    t[1]->right = t[4];
    Solution s;
    cout<<s.isValidBST(t[0])<<endl;
}
