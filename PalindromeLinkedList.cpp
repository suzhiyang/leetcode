class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode dummy(0);
        ListNode *tail = &dummy, *slow = head, *fast = head, *tmp;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = slow->next;
        slow->next = NULL;
        while(p != NULL)
        {
            tmp = p->next;
            p->next = tail->next;
            tail->next = p;
            p = tmp;
        }
        ListNode *rp = dummy.next;
        p = head;
        while(rp != NULL)
        {
            if (rp->val != p->val) return false;
            rp = rp->next; p = p->next;
        }
        return true;
    }
};
