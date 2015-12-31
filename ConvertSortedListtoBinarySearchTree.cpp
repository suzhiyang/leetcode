class Solution {
public:
    TreeNode *dfs(ListNode *head, ListNode *tail)
    {
        if (head == NULL || head == tail) return NULL;
        ListNode *slow = head, *fast = head;
        while(true)
        {
            fast = fast->next;
            if (fast == tail) break;
            fast = fast->next;
            if (fast == tail) break;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = dfs(head, slow);
        root->right = dfs(slow->next, tail);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, NULL);
    }
};
