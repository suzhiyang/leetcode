class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *tail = &dummy, *p = head, *cur;
        while(p != NULL)
        {
            if (p->next != NULL && p->val == p->next->val)
            {
                cur = p;
                while(p != NULL)
                {
                    if (p->val != cur->val) break;
                    p = p->next;
                }
            }
            else
            {
                tail->next = p;
                tail = p;
                p = p->next;
            }
        }
        tail->next = NULL;
        return dummy.next;
    }
};
