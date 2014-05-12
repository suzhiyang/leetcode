#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > r;
        if (root == NULL) return r;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        vector<int> leveli; //level i
        int currentlevel = 0;
        while(!q.empty())
        {
            pair<TreeNode *, int> t = q.front();
            q.pop();
            if (t.second > currentlevel)
            {
                r.push_back(leveli);
                leveli.clear();
                currentlevel = t.second;
            }
            leveli.push_back(t.first->val);
            if (t.first->left != NULL) q.push(make_pair(t.first->left, t.second + 1));
            if (t.first->right != NULL) q.push(make_pair(t.first->right, t.second + 1));
        }
        if (!leveli.empty()) r.push_back(leveli);
        reverse(r.begin(), r.end());
        return r;
    }
};

int main()
{
    Solution s;
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
    vector<vector<int> > r = s.levelOrderBottom(root);
    for (int i = 0; i < r.size(); ++i)
    {
        for(int j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
    return 0;
}
