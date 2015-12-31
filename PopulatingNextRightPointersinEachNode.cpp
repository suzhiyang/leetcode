class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *p = root, *tmp;
        while(p->left != NULL)
        {
            tmp = p;
            while(p)
            {
                p->left->next = p->right;
                if (p->next != NULL)
                    p->right->next = p->next->left;
                p = p->next;
            }
            p = tmp->left;
        }
    }
};
