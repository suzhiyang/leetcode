#include <vector>
#include "ds.h"

using namespace std;

class Solution {
public:
    TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
    {
        if (ps > preorder.size() - 1 || ps > pe) return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int i;
        for (i = is; i <= ie; ++i)
            if (inorder[i] == root->val) break;
        root->left = build(preorder, ps + 1, ps + i - is, inorder, is, i - 1);
        root->right = build(preorder, ps + i - is + 1, pe, inorder, i + 1, ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
};

int main()
{
    vector<int> v(1, 1);
    v.push_back(2);
    Solution s;
    s.buildTree(v, v);
}
