class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int n = 0, i;
        ListNode *p = head, dummy(0);
        dummy.next = head;
        while(p != NULL)
        {
            ++n; p = p->next;
        }
        k = k % n;
        if (k == 0) return head;
        p = head;
        for (i = 0; i < n - k - 1; ++i)
            p = p->next;
        dummy.next = p->next;
        p->next = NULL;
        p = dummy.next;
        while(p->next != NULL) p = p->next;
        p->next = head;
        return dummy.next;
    }
};
