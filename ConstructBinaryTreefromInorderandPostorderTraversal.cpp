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
    TreeNode *build(vector<int> &inorder, int s1, int e1,
                    vector<int> &postorder, int s2, int e2)
    {
        TreeNode *root = new TreeNode(postorder[e2]);
        if (s1 == e1) return root;
        int i;
        for (i = e1; i >= s1; --i)
            if (inorder[i] == postorder[e2]) break;
        if (i < e1) root->right = build(inorder, i + 1, e1,
                                        postorder, e2 - e1 + i, e2 - 1);
        if (i > s1) root->left = build(inorder, s1, i - 1,
                                       postorder, s2, s2 + i - s1 - 1);
//        if (i > s1) root->left = build(inorder, s1, i - 1,
//                                       postorder, e2 - e1 + s1, e2 - e1 + i - 1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
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
    int a[] = {4,5,2,3,1}, b[] = {4,2,5,1,3};
    vector<int> postorder(a, a + 5), inorder(b, b + 5);
    TreeNode *root = s.buildTree(inorder, postorder);
//     int a[] = {1,2}, b[] = {2,1};
//     vector<int> preorder(a, a + 2), inorder(b, b + 2);
//     TreeNode *root = s.buildTree(preorder, inorder);
    vector<int> result = preorderTraversal(root);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<",";
    cout<<endl;
    return 0;
}
