#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *first, *second, *prev, *newhead = NULL, *temp;
        first = head;
        second = head->next;
        newhead = second;
        while(1)
        {
            if (second != newhead) prev->next = second;
            temp = second->next;
            second->next = first;
            first->next = temp;
            prev = first;
            first = temp;
            if (first == NULL) break;
            if (first->next != NULL)
                second = first->next;
            else break;
        }
        return newhead;
    }
};

int main()
{
    Solution s;
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    h->next->next->next->next->next = new ListNode(6);
    h->next->next->next->next->next->next = new ListNode(7);

    printlist(h);
    printlist(s.swapPairs(h));
    printlist(h->next);
    printlist(s.swapPairs(h->next));

    return 0;
}
