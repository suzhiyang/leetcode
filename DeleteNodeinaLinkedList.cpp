class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *n1 = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete n1;
    }
};
