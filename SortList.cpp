class Solution {
public:
    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode dummy(0), *p1 = a, *p2 = b;
        ListNode *tail = &dummy;
        while(p1 && p2)
        {
            if (p1->val > p2->val)
            {
                tail->next = p2;
                p2 = p2->next;
            }
            else
            {
                tail->next = p1;
                p1 = p1->next;
            }
            tail = tail->next;
        }
        if (p1) tail->next = p1;
        else tail->next = p2;
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head, *a, *b;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        a = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(head);
        return merge(a, b);
    }
};
