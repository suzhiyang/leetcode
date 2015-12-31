class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode dummy(0);
        ListNode *prev = &dummy, *p1 = head, *p2 = head->next, *tmp;
        dummy.next = head;
        while(p1 != NULL && p2 != NULL)
        {
            prev->next = p2;
            tmp = p2->next;
            p2->next = p1;
            p1->next = tmp;

            prev = p1;
            if (tmp == NULL) break;
            p1 = tmp;
            p2 = tmp->next;
        }
        return dummy.next;
    }
};
