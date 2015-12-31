class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > r;
        if (root == NULL) return r;
        deque<TreeNode *> q[2];
        q[0].push_back(root);
        int i, n;
        for (i = 0; !q[i].empty(); i ^= 1)
        {
            n = i ^ 1;
            vector<int> cur;
            while(!q[i].empty())
            {
                TreeNode *t;
                if (i == 0)
                {
                    t = q[i].front();
                    q[i].pop_front();
                    if (t->left != NULL) q[n].push_back(t->left);
                    if (t->right != NULL) q[n].push_back(t->right);
                }
                else
                {
                    t = q[i].back();
                    q[i].pop_back();
                    if (t->right != NULL) q[n].push_front(t->right);
                    if (t->left != NULL) q[n].push_front(t->left);
                }
 
                cur.push_back(t->val);
            }
            r.push_back(cur);
        }
        return r;
    }
};
