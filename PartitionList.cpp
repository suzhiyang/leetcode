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

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return head;
        ListNode *ppart1tail, *pcurrent, *ppart2head, *ppart2prev;
        pcurrent = head;
        ppart2head = NULL;
        ppart1tail = NULL;
        ppart2prev = NULL;
        while(pcurrent != NULL)
        {
            ListNode *ptemp = pcurrent->next;
            pcurrent->next = NULL;
            if (pcurrent->val < x)
            {
                if (ppart1tail == NULL)
                {
                    ppart1tail = pcurrent;
                    head = pcurrent;
                }
                else
                {
                    ppart1tail->next = pcurrent;
                    ppart1tail = pcurrent;
                }
            }
            else if (ppart2head == NULL)
            {
                ppart2head = pcurrent;
                ppart2prev = pcurrent;
            }
            else if (ppart2prev != NULL)
            {
                ppart2prev->next = pcurrent;
                ppart2prev = pcurrent;
            }
            pcurrent = ptemp;
        }
        if (ppart1tail != NULL) ppart1tail->next = ppart2head;
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
    head->next->next->next = new ListNode(4);
    PrintList(head);

    Solution s;
    head = s.partition(head, 2);
    PrintList(head);

    head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    PrintList(head);
    head = s.partition(head, 3);
    PrintList(head);

    head = new ListNode(1);
    PrintList(head);
    head = s.partition(head, 1);
    PrintList(head);

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    PrintList(head);
    head = s.partition(head, 4);
    PrintList(head);

    return 0;
}
