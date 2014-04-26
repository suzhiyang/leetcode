/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        ListNode *pa = a, *pb = b, *head = NULL, *tail;
        if (a == NULL) return b;
        else if (b == NULL) return a;
        if (pa->val > pb->val)
        {
            head = pb;
            pb = pb->next;
        }
        else
        {
            head = pa;
            pa = pa->next;
        }
        tail = head;
        while(pa != NULL && pb != NULL)
        {
            if (pa->val > pb->val)
            {
                tail->next = pb;
                pb = pb->next;
            }
            else
            {
                tail->next = pa;
                pa = pa->next;
            }
            tail = tail->next;
        }
        if (pa == NULL) tail->next = pb;
        else tail->next = pa;
        return head;
    }

};
