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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, *slow = head, *prev = NULL;
        int i;
        for(i = 0; i < n; ++i)
            p = p->next;
        while(p != NULL)
        {
            prev = slow;
            slow = slow->next;
            p = p->next;
        }
        if (prev == NULL) return head->next;
        prev->next = slow->next;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *l[10], *h;
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
    s.removeNthFromEnd(l[0], 2);
    printlist(l[0]);
    h = s.removeNthFromEnd(l[0], 4);
    printlist(h);
}
