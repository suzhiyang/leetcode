class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), *p, *ins, *first, *tmp;
        dummy.next = head;
        ins = &dummy;
        int i;
        for (i = 1; i < m; ++i)
            ins = ins->next;
        p = ins->next;
        first = ins->next;
        for (; i <= n; ++i)
        {
            tmp = p->next;
            p->next = ins->next;
            ins->next = p;
            p = tmp;
        }
        first->next = p;
        return dummy.next;
    }
};
