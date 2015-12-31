class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *r = reverseList(head->next), *p = head->next;
        p->next = head;
        head->next = NULL;
        return r;
    }
};
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode dummy(0), *p = head, *t;
//         while(p != NULL)
//         {
//             t = p->next;
//             p->next = dummy.next;
//             dummy.next = p;
//             p = t;
//         }
//         return dummy.next;
//     }
// };
