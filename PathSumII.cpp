#include <iostream>
#include <vector>

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
    vector<vector<int> > m_pathvec;
public:
    void CheckPathSum(TreeNode *root, int sum, int currentsum, vector<int> &currentpath)
    {
        vector<int> temp(currentpath);
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val + currentsum)
                m_pathvec.push_back(temp);
        }
        if (root->left != NULL) CheckPathSum(root->left, sum, root->val + currentsum, temp);
        if (root->right != NULL) CheckPathSum(root->right, sum, root->val + currentsum, temp);
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == NULL) return m_pathvec;
        vector<int> currentpath;
        CheckPathSum(root, sum, 0, currentpath);
        return m_pathvec;
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int> > pathvec;
    pathvec = s.pathSum(root, 22);
    for (int i = 0; i < pathvec.size(); ++i)
    {
        for (int j = 0; j < pathvec[i].size(); ++j)
            cout<<pathvec[i][j]<<",";
        cout<<endl;
    }
    return 0;
}
