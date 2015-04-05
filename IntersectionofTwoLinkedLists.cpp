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
    ListNode *p = head;
    while(p != NULL)
    {
        cout<<p->val<<",";
        p = p->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0, i;
        ListNode *pa = headA, *pb = headB;
        while(pa != NULL)
        {
            pa = pa->next;
            ++l1;
        }
        while(pb != NULL)
        {
            pb = pb->next;
            ++l2;
        }
        pa = headA; pb = headB;
        if (l1 > l2)
        {
            for (i = 0; i < l1 - l2; ++i)
                pa = pa->next;
        }
        else if (l1 < l2)
        {
            for (i = 0; i < l2 - l1; ++i)
                pb = pb->next;
        }
        while(pa != NULL && pb != NULL)
        {
            if (pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
};

int main()
{
    ListNode *pa = new ListNode(1);
    pa->next = new ListNode(2);
    ListNode *pb = new ListNode(2);
    Solution s;
    printlist(s.getIntersectionNode(pa, pb));
}
