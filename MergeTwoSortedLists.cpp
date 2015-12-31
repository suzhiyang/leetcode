class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h = NULL, *tail = NULL, *p1 = l1, *p2 = l2;
        if (l1 == NULL && l2 == NULL) return NULL;
        while(p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                if (h == NULL) {h = p1; tail = p1;}
                else {tail->next = p1; tail = p1;}
                p1 = p1->next;
            }
            else
            {
                if (h == NULL) {h = p2; tail = p2;}
                else {tail->next = p2; tail = p2;}
                p2 = p2->next;
            }
        }
        if (p1 == NULL && p2 != NULL)
        {
            if (h == NULL) return p2;
            else tail->next = p2;
        }
        else
        {
            if (h == NULL) return p1;
            else tail->next = p1;
        }
        return h;
    }
};
