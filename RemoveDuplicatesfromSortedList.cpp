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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p1 = head, *p2, *t;
        p2 = head->next;
        while(p1 != NULL)
        {
            while(p2 != NULL && p1->val == p2->val)
            {
                t = p2;
                p2 = p2->next;
                delete t;
            }
            p1->next = p2;
            p1 = p2;
            if (p2 != NULL) p2 = p2->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *l[10];
    l[0] = new ListNode(1);
    l[1] = new ListNode(1);
    l[2] = new ListNode(2);
    l[3] = new ListNode(3);
    l[4] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(1);
    l[0]->next = l[1];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);
}
