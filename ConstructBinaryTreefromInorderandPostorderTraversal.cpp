#include <iostream>
#include <vector>
#include "ds.h"

using namespace std;

class Solution {
public:
    TreeNode *dfs(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe)
    {
        if (ps > pe || pe < 0) return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int i;
        for (i = is; i <= ie; ++i)
            if (inorder[i] == root->val) break;
        root->left = dfs(inorder, is, i - 1, postorder, ps, ps + i - is - 1);
        root->right = dfs(inorder, i + 1, ie, postorder, ps + i - is, pe - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

int main()
{
    vector<int> v(1, 2);
    v.push_back(1);
    Solution s;
    s.buildTree(v, v);
}
