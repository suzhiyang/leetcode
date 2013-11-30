#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Notes: needn't to link the sorted list to the unsorted head, namely cut the list into
 * 2 part in the beginning.
 */

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return NULL;
        ListNode *punsort, *pcurrent = head->next;
        head->next = NULL;
        while(pcurrent != NULL)
        {
            punsort = pcurrent->next;
            ListNode *pinsert = head, *pinsertprev = NULL;
            while(pinsert != NULL)
            {
                if (pinsert->val > pcurrent->val) break;
                pinsertprev = pinsert;
                pinsert = pinsert->next;
            }
            if (pinsert == head)
            {
                pcurrent->next = head;
                head = pcurrent;
            }
            else
            {
                pinsertprev->next = pcurrent;
                pcurrent->next = pinsert;
            }
            pcurrent = punsort;
        }
        return head;
    }
};

void PrintList(ListNode *head)
{
    ListNode *p = head;
    while(p != NULL)
    {
        cout<<p->val<<",";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    PrintList(head);

    Solution s;
    head = s.insertionSortList(head);
    PrintList(head);

    head = new ListNode(2);
    head->next = new ListNode(1);
    PrintList(head);
    head = s.insertionSortList(head);
    PrintList(head);
    return 0;
}
