class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode *> q[2];
        vector<vector<int> > r;
        if (root == NULL) return r;
        q[0].push(root);
        int i, nq;
        for (i = 0; !q[i].empty(); i ^= 1)
        {
            nq = i ^ 1;
            vector<int> cur;
            while(!q[i].empty())
            {
                TreeNode *t = q[i].front();
                q[i].pop();
                cur.push_back(t->val);
                if (t->left != NULL) q[nq].push(t->left);
                if (t->right != NULL) q[nq].push(t->right);
            }
            r.push_back(cur);
        }
        return r;
    }
};
