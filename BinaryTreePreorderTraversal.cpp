class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while(cur != NULL || !stk.empty())
        {
            if (cur == NULL)
            {
                cur = stk.top();
                stk.pop();
            }
            r.push_back(cur->val);
            if (cur->right) stk.push(cur->right);
            cur = cur->left;
        }
        return r;
    }
};
