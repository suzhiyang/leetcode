#include <iostream>
#include "ds.h"
using namespace std;

class Solution {
public:
    void inorder(TreeNode *root, TreeNode **prev, TreeNode **w1, TreeNode **w2)
    {
        if (root == NULL) return;
        inorder(root->left, prev, w1, w2);
        if (*prev != NULL && (*prev)->val > root->val)
        {
            if (*w1 == NULL) {*w1 = *prev; *w2 = root;}
            else *w2 = root;
        }
        *prev = root;
        inorder(root->right, prev, w1, w2);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *w1 = NULL, *w2 = NULL, *prev = NULL;
        inorder(root, &prev, &w1, &w2);
        swap(w1->val, w2->val);
    }
};

// class Solution {
// public:
//     TreeNode *prenode(TreeNode *root)
//     {
//         TreeNode *t = root->left;
//         while(t->right != NULL && t->right != root)
//             t = t->right;
//         return t;
//     }

//     void recoverTree(TreeNode* root) {
//         if (root == NULL) return;
//         TreeNode *cur = root, *pre, *prev = NULL, *w1 = NULL, *w2 = NULL;
//         while(cur != NULL)
//         {
//             if (cur->left != NULL)
//             {
//                 pre = prenode(cur);
//                 if (pre->right == NULL)
//                 {
//                     pre->right = cur;
//                     cur = cur->left;
//                 }
//                 else // (pre->right == cur)
//                 {
//                     if (prev != NULL)
//                     {
//                         if (prev->val > cur->val)
//                         {
//                             if (w1 == NULL) {w1 = prev; w2 = cur;}
//                             else w2 = cur;
//                         }
//                     }
//                     prev = cur;
//                     pre->right = NULL;
//                     cur = cur->right;
//                 }
//             }
//             else
//             {
//                 if (prev != NULL)
//                 {
//                     if (prev->val > cur->val)
//                     {
//                         if (w1 == NULL) {w1 = prev; w2 = cur;}
//                         else w2 = cur;
//                     }
//                 }
//                 prev = cur;
//                 cur = cur->right;
//             }
//         }
//         swap(w1->val, w2->val);
//     }
// };

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(4);
    Solution s;
    printinorder(root);
    cout<<endl;
    s.recoverTree(root);
    printinorder(root);
}
