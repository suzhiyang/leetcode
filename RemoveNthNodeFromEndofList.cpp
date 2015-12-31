class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *lowprev = head, *fast = head, *t;
        if (head == NULL) return head;
        int i;
        for (i = 0; i <= n && fast != NULL; ++i)
            fast = fast->next;
        if (fast == NULL && i == n) {t = head->next; delete head; return t;}
        while (fast != NULL)
        {
            lowprev = lowprev->next;
            fast = fast->next;
        }
        t = lowprev->next;
        lowprev->next = t->next;
        delete t;
        return head;
    }
};
