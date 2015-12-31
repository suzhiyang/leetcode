class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *tmp;
        dummy.next = head;
        ListNode *prev = &dummy, *p = head;
        while(p != NULL)
        {
            if (p->val == val)
            {
                prev->next = p->next;
                delete p;
                p = prev->next;
            }
            else
            {
                prev = p;
                p = p->next;
            }
        }
        return dummy.next;
    }
};
