class BSTIterator {
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while(cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }            
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stk.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = stk.top();
        stk.pop();
        int r = cur->val;
        if (cur->right)
        {
            cur = cur->right;
            while(cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
        }
        return r;
    }
};
