#include <vector>
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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        else if (root->left != NULL && root->right != NULL)
            return leftrightcrosseq(root->left, root->right);
        return false;
    }

    bool leftrightcrosseq(TreeNode *l, TreeNode *r)
    {
        if (l != NULL && r != NULL && l->val != r->val) return false;
        if (l == NULL && r == NULL) return true;
        if ((l == NULL && r != NULL) || (l != NULL && r == NULL)) return false;
        bool flag = false;
        if (l->left == NULL && r->right == NULL) flag == true;
        else if (l->left != NULL && r->right != NULL)
        {
            flag = leftrightcrosseq(l->left, r->right);
            if (flag == false) return false;
        }
        else return false;
        if (l->right == NULL && r->left == NULL) flag == true;
        else if (l->right != NULL && r->left != NULL)
        {
            flag = leftrightcrosseq(l->right, r->left);
            if (flag == false) return false;
        }
        else return false;
        return true;
    }
};

int main()
{
    Solution s;
    //                       1
    //                      / \
    //                     2   2
    //                    /     \
    //                   3       3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout<<s.isSymmetric(root)<<endl;
    return 0;
}
