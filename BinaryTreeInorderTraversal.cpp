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
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result, temp;
        if (root == NULL) return result;
        else
        {
            temp.clear();
            temp = inorderTraversal(root->left);
            for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
                result.push_back(*it);
            result.push_back(root->val);
            temp.clear();
            temp = inorderTraversal(root->right);
            for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
                result.push_back(*it);
        }
    }
};

int main()
{
    TreeNode *t[3];
    t[0] = new TreeNode(1);
    t[1] = new TreeNode(2);
    t[2] = new TreeNode(3);
    t[0]->right = t[1];
    t[1]->left = t[2];
    Solution s;
    vector<int> result = s.inorderTraversal(t[0]);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
        cout<<*it<<",";
    cout<<endl;
}
