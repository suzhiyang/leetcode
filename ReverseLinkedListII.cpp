#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printlist(ListNode *head)
{
    while(head != NULL)
    {
        cout<<head->val<<",";
        head = head->next;
    }
    cout<<endl;
}

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *pm, *pn, *ppm, *pnn; //previous pm, pn next
        ListNode *p1, *p2, *p2n;
        int i;
        if (m > 1)
        {
            ppm = head;
            for(i = 0; i < m - 2; ++i)
                ppm = ppm->next;
            pm = ppm->next;
        }
        else
        {
            ppm = NULL;
            pm = head;
        }
        p1 = pm;
        p2 = pm->next;
        for(i = m; i < n; ++i)
        {
            p2n = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2n;
        }
        pm->next = p2;
        if (m > 1) ppm->next = p1;
        else head = p1;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *l[10];
    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[3] = new ListNode(4);
    l[4] = new ListNode(5);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    printlist(l[0]);
    l[0] = s.reverseBetween(l[0], 2, 4);
    printlist(l[0]);
    l[0] = s.reverseBetween(l[0], 1, 4);
    printlist(l[0]);
    l[0] = s.reverseBetween(l[0], 1, 5);
    printlist(l[0]);


    l[0] = new ListNode(1);
    printlist(l[0]);
    l[0] = s.reverseBetween(l[0], 1, 1);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[0]->next = l[1];
    printlist(l[0]);
    l[0] = s.reverseBetween(l[0], 1, 2);
    printlist(l[0]);
}
