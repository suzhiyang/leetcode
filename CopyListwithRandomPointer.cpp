#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/* Step 1:
 * Deep copy the nodes and link them to the orignial nodes
 * Step 2:
 * Travel the list and make the random pointer point to the next of the original node
 * Step 3:
 * Decompose the list into 2 lists
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return NULL;
        RandomListNode *p = head, *temp = NULL;
        while(p != NULL)
        {
            RandomListNode *pnew = new RandomListNode(p->label);
            pnew->next = p->next;
            pnew->random = p->random;
            temp = p->next;
            p->next = pnew;
            p = temp;
        }

        p = head;
        if (p != NULL) p = p->next;
        while(p != NULL)
        {
            if (p->random != NULL) p->random = p->random->next;
            if (p->next == NULL) break;
            p = p->next->next;
        }

        p = head;
        RandomListNode *pnewhead = NULL;
        if (p != NULL) pnewhead = p->next;
        while(p != NULL)
        {
            temp = p->next;
            p->next = temp->next;
            if (temp->next != NULL) temp->next = temp->next->next;
            p = p->next;
        }

        return pnewhead;
    }
};

void PrintList(RandomListNode *head)
{
    RandomListNode *p = head;
    while(p != NULL)
    {
        cout<<p->label<<",";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    PrintList(head);
    Solution s;
    RandomListNode *pnewhead = s.copyRandomList(head);
    PrintList(head);
    PrintList(pnewhead);
    return 0;
}
