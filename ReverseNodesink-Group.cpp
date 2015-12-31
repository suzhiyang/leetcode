#include <iostream>
#include "ds.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *nt = head, *p = head, *tmp;
        int i;
        while (p != NULL)
        {
            for (i = 0; p != NULL && i < k; ++i)
            {
                if (i == 0) nt = p;
                tmp = p->next;
                p->next = prev->next;
                prev->next = p;
                p = tmp;
            }
            nt->next = p;
            if (i < k) break;
            prev = nt;
        }
        if (i < k)
        {
            p = prev->next;
            prev->next = NULL;
            while (p != NULL)
            {
                tmp = p->next;
                p->next = prev->next;
                prev->next = p;
                p = tmp;
            }
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    printlist(h);
    Solution s;
    h = s.reverseKGroup(h, 3);
    printlist(h);
}
