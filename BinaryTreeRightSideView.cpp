#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> r;
        if (root == NULL) return r;
        queue<TreeNode *> q[2];
        int qnum, qnext;
        q[0].push(root);
        for (qnum = 0; !q[qnum].empty(); qnum ^= 1)
        {
            qnext = qnum ^ 1;
            TreeNode *t;
            while(!q[qnum].empty())
            {
                t = q[qnum].front();
                q[qnum].pop();
                if (t->left != NULL) q[qnext].push(t->left);
                if (t->right != NULL) q[qnext].push(t->right);
            }
            r.push_back(t->val);
        }
        return r;
    }
};
