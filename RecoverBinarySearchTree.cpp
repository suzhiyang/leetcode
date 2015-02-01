#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

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

// This is not O(1) space algorithm rigorously 
class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> nodes;
        vector<int> vals;
        Inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < nodes.size(); ++i)
            nodes[i]->val = vals[i];
    }

    void Inorder(TreeNode *root, vector<TreeNode *> &nodes, vector<int> &vals)
    {
        if (root == NULL) return;
        Inorder(root->left, nodes, vals);
        nodes.push_back(root);
        vals.push_back(root->val);
        Inorder(root->right, nodes, vals);
    }
};
