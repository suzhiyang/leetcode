class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0), even(0), *p = head;
        ListNode *ot = &odd, *et = &even;
        int count = 1;
        while(p != NULL)
        {
            if (count % 2 == 0)
            {
                et->next = p;
                et = et->next;
            }
            else
            {
                ot->next = p;
                ot = ot->next;
            }
            ++count;
            p = p->next;
        }
        et->next = NULL;
        ot->next = even.next;
        return odd.next;
    }
};
