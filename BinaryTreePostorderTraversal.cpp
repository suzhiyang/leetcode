class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *prev = NULL, *cur;
        stack<TreeNode *> stk;
        vector<int> r;
        if (root == NULL) return r;
        stk.push(root);
        while(!stk.empty())
        {
            cur = stk.top();
            if (prev == NULL || prev->left == cur || prev->right == cur)
            {
                if (cur->left) stk.push(cur->left);
                else if (cur->right) stk.push(cur->right);
            }
            else if (prev == cur->left)
            {
                if (cur->right) stk.push(cur->right);
            }
            else
            {
                r.push_back(cur->val);
                stk.pop();
            }
            prev = cur;
        }
        return r;
    }
};

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> r;
//         stack<pair<TreeNode *, bool> > stk; // bool: expand?
//         TreeNode *cur = root;
//         while (cur != NULL || !stk.empty())
//         {
//             if (cur->left == NULL && cur->right == NULL)
//             {
//                 r.push_back(cur->val);
//                 if (!stk.empty())
//                 {
//                     pair<TreeNode *, bool> p = stk.top();
//                     stk.pop();
//                     while(p.second == false && !stk.empty())
//                     {
//                         r.push_back(p.first->val);
//                         p = stk.top();
//                         stk.pop();
//                     }
//                     if (p.second) cur = p.first;
//                     else
//                     {
//                         r.push_back(p.first->val);
//                         cur = NULL;
//                     }
//                 }
//                 else cur = NULL;
//             }
//             else if (cur->left != NULL)
//             {
//                 stk.push(make_pair(cur, false));
//                 if (cur->right) stk.push(make_pair(cur->right, true));
//                 cur = cur->left;
//             }
//             else
//             {
//                 stk.push(make_pair(cur, false));
//                 cur = cur->right;
//             }
//         }
//         return r;
//     }
// };
