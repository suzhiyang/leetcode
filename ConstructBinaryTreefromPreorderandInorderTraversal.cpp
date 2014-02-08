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
public:
    TreeNode *build(vector<int> &preorder, int s1, int e1,
                    vector<int> &inorder, int s2, int e2)
    {
        TreeNode *root = new TreeNode(preorder[s1]);
        if (s1 == e1) return root;
        int i;
        for (i = s2; i <= e2; ++i)
            if (inorder[i] == preorder[s1]) break;
        if (i > s2) root->left = build(preorder, s1 + 1, s1 + i - s2,
                                       inorder, s2, i - 1);
        if (i < e2) root->right = build(preorder, s1 + i - s2 + 1, s1 + i - s2 + e2 - i,
                                        inorder, i + 1, e2);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result, temp;
    if (root == NULL) return result;
    else
    {
        result.push_back(root->val);
        temp.clear();
        temp = preorderTraversal(root->left);
        for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
            result.push_back(*it);
        temp.clear();
        temp = preorderTraversal(root->right);
        for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
            result.push_back(*it);
    }
}


int main()
{
    Solution s;
//     int a[] = {1,2,4,5,3}, b[] = {4,2,5,1,3};
//     vector<int> preorder(a, a + 5), inorder(b, b + 5);
//     TreeNode *root = s.buildTree(preorder, inorder);
    int a[] = {1,2}, b[] = {2,1};
    vector<int> preorder(a, a + 2), inorder(b, b + 2);
    TreeNode *root = s.buildTree(preorder, inorder);
    vector<int> result = preorderTraversal(root);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<",";
    cout<<endl;
    return 0;
}
