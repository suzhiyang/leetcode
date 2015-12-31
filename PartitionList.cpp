class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode d1(0), d2(0);
        ListNode *p1 = &d1, *p2 = &d2;
        while(head != NULL)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = head;
            }
            else
            {
                p2->next = head;
                p2 = head;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = d2.next;
        return d1.next;
    }
};

// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode *prev = &dummy, *ins = &dummy, *p = head, *tmp;
//         while(p != NULL)
//         {
//             if (p->val < x)
//             {
//                 if (prev != ins)
//                 {
//                     prev->next = p->next;
//                     tmp = ins->next;
//                     ins->next = p;
//                     p->next = tmp;
//                     p = prev->next;
//                 }
//                 else
//                 {
//                     prev = prev->next;
//                     p = p->next;
//                 }
//                 ins = ins->next;
//             }
//             else
//             {
//                 prev = p;
//                 p = p->next;
//             }
//         }
//         return dummy.next;
//     }
// };
