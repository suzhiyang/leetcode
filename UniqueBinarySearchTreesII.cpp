class Solution {
public:
    vector<TreeNode*> generate(int s, int e)
    {
        vector<TreeNode *> r;
        if (s > e) r.push_back(NULL);
        else if (s == e) r.push_back(new TreeNode(s));
        else
        {
            int i, j, k;
            for (i = s; i <= e; ++i)
            {
                vector<TreeNode *> lt = generate(s, i - 1);
                vector<TreeNode *> rt = generate(i + 1, e);
                for (j = 0; j < lt.size(); ++j)
                {
                    for (k = 0; k < rt.size(); ++k)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = lt[j];
                        root->right = rt[k];
                        r.push_back(root);
                    }
                }
            }
        }
        return r;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
