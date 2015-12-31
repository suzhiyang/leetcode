class Solution {
public:
    void insert(ListNode &dummy, ListNode *node)
    {
        ListNode *p = dummy.next, *prev = &dummy;
        while(p != NULL)
        {
            if (p->val > node->val) break;
            prev = p;
            p = p->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    
    ListNode *insertionSortList(ListNode* head) {
        ListNode dummy(0), *p = head, *t;
        while(p != NULL)
        {
            t = p->next;
            p->next = NULL;
            insert(dummy, p);
            p = t;
        }
        return dummy.next;
    }
};
