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
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head, *cur = head->next, *newhead = NULL, *tail = NULL;
        // Determine the new head first
        if (prev->val != cur->val) // head is the new head
        {
            newhead = head;
            if (cur->next != NULL && cur->val != cur->next->val)
                tail = head->next;
            else tail = head;
        }
        else
        {
            while(cur->next != NULL)
            {
                if (prev->val != cur->val && cur->val != cur->next->val)
                    break;
                prev = cur;
                cur = cur->next;
            }
            if (cur->next == NULL)
            {
                if (prev->val == cur->val) return NULL;
                else return cur;
            }
            newhead = cur;
            tail = cur;
        }
        prev = cur;
        cur = cur->next;
        if (cur == NULL) return newhead;
        while(cur->next != NULL)
        {
            if (prev->val != cur->val && cur->val != cur->next->val)
            {
                tail->next = cur;
                tail = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        if (prev->val != cur->val)
        {
            tail->next = cur;
        }
        else tail->next = NULL;
        return newhead;
    }
};

int main()
{
    Solution s;
    ListNode *l[10];
    l[0] = new ListNode(1);
    l[1] = new ListNode(1);
    l[2] = new ListNode(2);
    l[3] = new ListNode(2);
    l[4] = new ListNode(3);
    l[5] = new ListNode(3);
    l[6] = new ListNode(4);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    l[4]->next = l[5];
    l[5]->next = l[6];
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

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[0]->next = l[1];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(2);
    l[0]->next = l[1];
    l[1]->next = l[2];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(1);
    l[2] = new ListNode(2);
    l[0]->next = l[1];
    l[1]->next = l[2];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(1);
    l[2] = new ListNode(2);
    l[3] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[3] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(2);
    l[3] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    printlist(l[0]);
    l[0] = s.deleteDuplicates(l[0]);
    printlist(l[0]);
}
