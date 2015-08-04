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

class Solution {
public:
    void findpath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path)
    {
        if (root == NULL) return;
        path.push_back(root);
        if (root == p) return;
        int k = path.size();
        findpath(root->left, p, path);
        if (path.back() == p) return;
        while(path.size() > k)
            path.pop_back();
        findpath(root->right, p, path);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p1, p2;
        findpath(root, p, p1);
        findpath(root, q, p2);
        int i = 0;
        while(i < p1.size() && i < p2.size())
        {
            if (p1[i] == p2[i]) ++i;
            else break;
        }
        if (i == 0) return root;
        return p1[--i];
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
    vector<TreeNode *> v;
    s.findpath(root, root->left->right, v);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]->val<<",";
    }
    cout<<endl;
    return 0;
}
