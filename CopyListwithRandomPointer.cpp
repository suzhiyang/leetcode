/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head, dummy(0), *t, *tail;
        if (head == NULL) return NULL;
        while(p != NULL)
        {
            t = new RandomListNode(p->label);
            t->next = p->next;
            t->random = p->random;
            p->next = t;
            p = t->next;
        }
        p = head->next;
        while (p != NULL)
        {
            if (p->random != NULL) p->random = p->random->next;
            if (p->next == NULL) break;
            p = p->next->next;
        }
        p = head; tail = &dummy;
        while(p != NULL)
        {
            tail->next = p->next;
            tail = tail->next;
            p->next = tail->next;
            p = tail->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
