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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *s1 = head, *s2 = head;
        while(s1 != NULL && s2 != NULL)
        {
            s1 = s1->next;
            s2 = s2->next;
            if (s2 == NULL || s2->next == NULL) break;
            else s2 = s2->next;
            if (s1 == s2)
            {
                ListNode *coinp = s1;
                s1 = head;
                while (s1 != coinp)
                {
                    s1 = s1->next;
                    coinp = coinp->next;
                }
                return s1;
            }
        }
        return NULL;
    }
};
