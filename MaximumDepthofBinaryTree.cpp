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
    int m_maxdepth;
public:
    void Depth(TreeNode *root, int currentdepth)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (m_maxdepth < currentdepth) m_maxdepth = currentdepth;
            return;
        }
        if (root->left != NULL) Depth(root->left, currentdepth + 1);
        if (root->right != NULL) Depth(root->right, currentdepth + 1);
    }
    
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        m_maxdepth = 1;
        Depth(root, 1);
        return m_maxdepth;
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
    cout<<s.maxDepth(root)<<endl;
    cout<<s.maxDepth(root->left->left)<<endl;
    cout<<s.maxDepth(root->right->right->right)<<endl;
    return 0;
}
