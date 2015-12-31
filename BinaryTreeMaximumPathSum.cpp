#include <iostream>
#include "ds.h"

using namespace std;

class Solution {
private:
    int maxsum;
public:
    int dfs(TreeNode *root)
    {
        int rootmax = root->val, lmax = INT_MIN, rmax = INT_MIN, t;
        if (root->left != NULL) lmax = dfs(root->left);
        maxsum = max(lmax, maxsum);
        if (root->right != NULL) rmax = dfs(root->right);
        maxsum = max(rmax, maxsum);
        t = root->val;
        if (lmax > 0) t += lmax;
        if (rmax > 0) t += rmax;
        maxsum = max(t, maxsum);
        if (max(lmax, rmax) > 0) rootmax += max(lmax, rmax);
        return rootmax;
    }
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        maxsum = root->val;
        dfs(root);
        return maxsum;
    }
};

int main()
{
    Solution sol;
    TreeNode *tc1 = new TreeNode(2);
    tc1->left = new TreeNode(9);
    tc1->right = new TreeNode(7);
    tc1->left->left = new TreeNode(-3);
    tc1->left->right = new TreeNode(-2);
    tc1->right->right = new TreeNode(8);
    TreeNode *tc2 = new TreeNode(-3);
    TreeNode *tc3 = new TreeNode(5);
    tc3->left = new TreeNode(4);
    tc3->right = new TreeNode(8);
    tc3->left->left = new TreeNode(11);
    tc3->right->left = new TreeNode(13);
    tc3->right->right = new TreeNode(4);
    tc3->left->left->left = new TreeNode(7);
    tc3->left->left->right = new TreeNode(2);
    tc3->right->right->right = new TreeNode(1);
    cout<<sol.maxPathSum(tc1)<<endl;
    cout<<sol.maxPathSum(tc2)<<endl;
    cout<<sol.maxPathSum(tc3)<<endl;
}
