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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == NULL) return head;
        ListNode *poldhead = head, *p = head, *pprev = NULL;
        int len = 0;
        while(p != NULL)
        {
            p = p->next;
            ++len;
        }
        k = len - k % len;
        if (k == len) return head;
        p = head;
        int num = 0;
        while(num < k)
        {
            if (num == k - 1) pprev = p;
            p = p->next;
            ++num;
        }
        head = p;
        pprev->next = NULL;
        while(p->next != NULL) p = p->next;
        p->next = poldhead;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    PrintList(head);

    Solution s;
    head = s.rotateRight(head, 2);
    PrintList(head);

    head = new ListNode(1);
    head->next = new ListNode(2);
    PrintList(head);
    head = s.rotateRight(head, 2);
    PrintList(head);
}
