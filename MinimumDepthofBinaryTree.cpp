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
    int m_mindepth;
public:
    void Depth(TreeNode *root, int currentdepth)
    {
        if (currentdepth >= m_mindepth) return;
        if (root->left == NULL && root->right == NULL)
        {
            if (m_mindepth > currentdepth) m_mindepth = currentdepth;
            return;
        }
        if (root->left != NULL) Depth(root->left, currentdepth + 1);
        if (root->right != NULL) Depth(root->right, currentdepth + 1);
    }
    
    
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        m_mindepth = 999999;
        Depth(root, 1);
        return m_mindepth;
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
    cout<<s.minDepth(root)<<endl;
    cout<<s.minDepth(root->left->left)<<endl;
    cout<<s.minDepth(root->right->right->right)<<endl;
    return 0;
}
