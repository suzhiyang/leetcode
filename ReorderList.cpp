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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || head->next == NULL) return;
        ListNode *reversehead, *iter = head;
        int number = 1;
        while(iter->next != NULL)
        {
            iter = iter->next;
            ++number;
        }
        reversehead = iter;

        // Reverse the latter half list
        number = (number + 1) / 2;
        iter = head;
        for (int i = 0; i < number - 1; ++i)
            iter = iter->next;
        ListNode *halfhead = iter->next;
        iter->next = NULL;
        reversehead = reverselist(halfhead);

        //Merge the two lists
        ListNode *iter1 = head, *iter2 = reversehead, *iter1next, *iter2next;
        while(iter1->next != NULL)
        {
            iter1next = iter1->next;
            iter2next = iter2->next;
            iter1->next = iter2;
            iter2->next = iter1next;
            iter1 = iter1next;
            iter2 = iter2next;
        }
        if (iter2 != NULL)
            iter1->next = iter2;
    }
    
    ListNode *reverselist(ListNode *head)
    {
        ListNode *previousp, *currentp, *nextp;
        previousp = head;
        currentp = head->next;
        if (currentp == NULL) return head;
        if (currentp->next != NULL ) nextp = currentp->next;
        else
        {
            head->next = NULL;
            currentp->next = head;
            return currentp;
        }
        head->next = NULL;
        while(nextp != NULL)
        {
            currentp->next = previousp;
            previousp = currentp;
            currentp = nextp;
            nextp = nextp->next;
        }
        currentp->next = previousp;
        return currentp;
    }

};

int main()
{
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

    Solution s;
    s.reorderList(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[3] = new ListNode(4);
    l[4] = new ListNode(5);
    l[5] = new ListNode(6);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    l[4]->next = l[5];
    printlist(l[0]);
    s.reorderList(l[0]);
    printlist(l[0]);

    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[0]->next = l[1];
    l[1]->next = l[2];
    printlist(l[0]);
    s.reorderList(l[0]);
    printlist(l[0]);


    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[0]->next = l[1];
    printlist(l[0]);
    s.reorderList(l[0]);
    printlist(l[0]);

    
    l[0] = new ListNode(1);
    l[0]->next = NULL;
    printlist(l[0]);
    s.reorderList(l[0]);
    printlist(l[0]);
    
    s.reorderList(NULL);
}
