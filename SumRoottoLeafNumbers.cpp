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
    int m_sum;
public:
    void PreorderTraverse(TreeNode *root, int rootval)
    {
        root->val = rootval * 10 + root->val;
        if (root->left == NULL && root->right == NULL) m_sum += root->val;
        else
        {
            if (root->left != NULL) PreorderTraverse(root->left, root->val);
            if (root->right != NULL) PreorderTraverse(root->right, root->val);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        m_sum = 0;
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) m_sum += root->val;
        if (root->left != NULL) PreorderTraverse(root->left, root->val);
        if (root->right != NULL) PreorderTraverse(root->right, root->val);
        return m_sum;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    Solution s;
    cout<<s.sumNumbers(root)<<endl;
    root = new TreeNode(9);
    cout<<s.sumNumbers(root)<<endl;
    return 0;
}
