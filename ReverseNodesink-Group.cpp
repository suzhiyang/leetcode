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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) return head;
        ListNode *tail, *newhead, *pnext, *pretail;
        bool islast;
        pnext = head;
        pretail = NULL;
        while(pnext != NULL)
        {
            tail = pnext;
            newhead = reversek(tail, k, &pnext);
            if (pretail == NULL) head = newhead;
            else pretail->next = newhead;
            pretail = tail;
        }
        return head;
    }

    ListNode *reversek(ListNode *head, int k, ListNode **pnext)
    {
        ListNode *newhead = NULL, *p = head, *t;
        int i = 0;
        while(p != NULL)
        {
            t = p->next;
            if (newhead == NULL)
            {
                newhead = p;
                p->next = NULL;
            }
            else
            {
                p->next = newhead;
                newhead = p;
            }
            p = t;
            ++i;
            if (i >= k) break;
        }
        *pnext = p;
        if (i < k) newhead = reversek(newhead, i, pnext);
        return newhead;
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
    l[5] = new ListNode(6);
    l[6] = new ListNode(7);
    l[7] = new ListNode(8);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    l[4]->next = l[5];
    l[5]->next = l[6];
    l[6]->next = l[7];
            
    printlist(l[0]);
//    ListNode *pnext;
//     l[0] = s.reversek(l[0], 3, &pnext);
//     printlist(l[0]);
//     printlist(pnext);
    l[0] = s.reverseKGroup(l[0], 3);
    printlist(l[0]);
    l[0] = s.reverseKGroup(l[0], 2);
    printlist(l[0]);
}

