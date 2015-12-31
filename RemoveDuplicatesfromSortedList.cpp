class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *tail = &dummy, *p = head;
        while(p != NULL)
        {
            if (tail == &dummy || tail->val != p->val)
            {
                tail->next = p;
                tail = p;
            }
            p = p->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
