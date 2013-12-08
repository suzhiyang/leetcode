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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *tail = NULL, *p1 = l1, *p2 = l2;
        int c = 0;
        while(p1 != NULL || p2 != NULL)
        {
            ListNode *t = new ListNode(c);
            if (p1 != NULL) t->val += p1->val;
            if (p2 != NULL) t->val += p2->val;
            c = t->val / 10;
            t->val = t->val % 10;
            if (head == NULL) head = t;
            if (tail == NULL) tail = t;
            else
            {
                tail->next = t;
                tail = t;
            }
            if (p1 != NULL) p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }
        if (c != 0) tail->next = new ListNode(1);
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
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    PrintList(l1);
    PrintList(l2);
    Solution s;
    ListNode *r = s.addTwoNumbers(l1, l2);
    PrintList(r);

    cout<<endl;
    l1 = new ListNode(9);
    l2 = new ListNode(2);
    r = s.addTwoNumbers(l1, l2);
    PrintList(l1);
    PrintList(l2);
    PrintList(r);

    cout<<endl;
    l1 = new ListNode(1);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l2 = new ListNode(9);
    r = s.addTwoNumbers(l1, l2);
    PrintList(l1);
    PrintList(l2);
    PrintList(r);
}
