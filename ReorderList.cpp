class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode dummy(0), *slow = head, *fast = head, *p, *tail;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        p = slow->next;
        slow->next = NULL;
        while(p != NULL)
        {
            ListNode *t = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = t;
        }
        p = head; tail = dummy.next;
        while(p != NULL && tail != NULL)
        {
            ListNode *t1 = p->next, *t2 = tail->next;
            p->next = tail;
            tail->next = t1;
            p = t1;
            tail = t2;
        }   
    }
};
