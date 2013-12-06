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
    TreeNode *m_prev;
public:
    Solution(): m_prev(NULL) {}

    void flatten(TreeNode *root) {
        if (root == NULL) return;
        if (m_prev != NULL) m_prev->right = root;
        m_prev = root;
        TreeNode *tempright = root->right;
        flatten(root->left);
        flatten(tempright);
        root->left = NULL; // **** This line is important!
    }
};

int main()
{
//                       1
//                      / \
//                     2   5
//                    / \   \
//                   3   4   6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;
    s.flatten(root);
    TreeNode *p = root;
    while(p != NULL)
    {
        cout<<p->val<<",";
        p = p->right;
    }
    cout<<endl;

    root = new TreeNode(1);
    root->right = new TreeNode(2);
    s.flatten(root);
    p = root;
    while(p != NULL)
    {
        cout<<p->val<<",";
        p = p->right;
    }
    cout<<endl;
}
