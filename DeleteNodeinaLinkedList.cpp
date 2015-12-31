class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *t = node->next;
        node->val = t->val;
        node->next = t->next;
        delete t;
    }
};
