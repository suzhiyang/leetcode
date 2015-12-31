class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        if (fast == NULL) return false;
        fast = fast->next;
        while(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
