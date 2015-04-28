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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *nh = NULL, *nt = NULL, *p = head; // new head, new tail
        while(p != NULL)
        {
            if (p->val != val)
            {
                if (nh == NULL)
                {
                    nh = p;
                    nt = p;
                }
                else
                {
                    nt->next = p;
                    nt = p;
                }
            }
            p = p->next;
        }
        if (nt != NULL) nt->next = NULL;
        return nh;
    }
};
