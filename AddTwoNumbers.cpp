class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cy = 0, t;
        ListNode *nh = NULL, *tail = NULL, *p1 = l1, *p2 = l2;
        while(p1 != NULL || p2 != NULL)
        {
            t = cy;
            if (p1 != NULL) {t += p1->val; p1 = p1->next;}
            if (p2 != NULL) {t += p2->val; p2 = p2->next;}
            if (tail == NULL)
            {
                nh = new ListNode(0);
                tail = nh;
            }
            else
            {
                tail->next = new ListNode(0);
                tail = tail->next;
            }
            cy = t / 10;
            tail->val = t % 10;
        }
        if (cy != 0) {tail->next = new ListNode(cy); tail = tail->next;}
        tail->next = NULL;
        return nh;
    }
};
