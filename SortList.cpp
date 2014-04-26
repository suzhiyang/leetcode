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
    void splitList(ListNode *head, ListNode **a, ListNode **b)
    {
        ListNode *p1 = head, *p2 = head, *p1prev = head;
        while (p2 != NULL)
        {
            p1prev = p1;
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) break;
            p2 = p2->next;
        }
        *a = head;
        *b = p1;
        p1prev->next = NULL;
    }

    ListNode *mergeList(ListNode *a, ListNode *b)
    {
        ListNode *pa = a, *pb = b, *head = NULL, *tail;
        if (pa->val > pb->val)
        {
            head = pb;
            pb = pb->next;
        }
        else
        {
            head = pa;
            pa = pa->next;
        }
        tail = head;
        while(pa != NULL && pb != NULL)
        {
            if (pa->val > pb->val)
            {
                tail->next = pb;
                pb = pb->next;
            }
            else
            {
                tail->next = pa;
                pa = pa->next;
            }
            tail = tail->next;
        }
        if (pa == NULL) tail->next = pb;
        else tail->next = pa;
        return head;
    }

    ListNode *mergesort(ListNode *head)
    {
        ListNode *a = NULL, *b = NULL;
        if (head == NULL || head->next == NULL) return head;

        splitList(head, &a, &b);
        ListNode *pa = NULL, *pb = NULL;
        pa = mergesort(a);
        pb = mergesort(b);
        head = mergeList(pa, pb);
        
        return head;
    }
    
    ListNode *sortList(ListNode *head) {
        // Merge sort, slow fast pointer to split list
        return mergesort(head);
    }
};

int main()
{
    Solution s;
    ListNode *h = new ListNode(4);
    h->next = new ListNode(7);
    h->next->next = new ListNode(5);
    h->next->next->next = new ListNode(1);
    h->next->next->next->next = new ListNode(3);
    h->next->next->next->next->next = new ListNode(6);
    h->next->next->next->next->next->next = new ListNode(2);

    ////////////////////unit test//////////////////////////
    ListNode *a, *b;
    ListNode *t = new ListNode(1);
    t->next = new ListNode(2);
    s.splitList(t, &a, &b);
    cout<<"A:"<<endl;
    printlist(a);
    cout<<"B:"<<endl;
    printlist(b);
    ///////////////////////////////////////////////////////

    printlist(h);
    printlist(s.sortList(h));
    return 0;
}
