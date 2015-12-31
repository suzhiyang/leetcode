class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode *> stk;
        TreeNode *t = root;
        while(t != NULL)
        {
            if (t->left != NULL)
            {
                stk.push(t);
                t = t->left;
            }
            else
            {
                r.push_back(t->val);
                t = t->right;
                while(t == NULL && !stk.empty())
                {
                    t = stk.top();
                    stk.pop();
                    r.push_back(t->val);
                    t = t->right;
                }
            }
        }
        return r;
    }
};
