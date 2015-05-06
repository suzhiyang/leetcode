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
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead = NULL, *p = head, *nextp = NULL;
        while(p != NULL)
        {
            nextp = p->next;
            p->next = newhead;
            newhead = p;
            p = nextp;
        }
        return newhead;
    }
};
