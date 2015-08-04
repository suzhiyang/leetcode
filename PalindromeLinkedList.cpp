#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void outputlist(ListNode *h)
{
    ListNode *p = h;
    while(p != NULL)
    {
        cout<<p->val<<",";
        p = p->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *l = head, *newhead = NULL, *t;
        while(l != NULL)
        {
            t = l->next;
            l->next = newhead;
            newhead = l;
            l = t;
        }
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *l = head, *f = head;
        while(f != NULL)
        {
            l = l->next;
            if (f->next != NULL) f = f->next->next;
            else break;
        }
        ListNode *pal = reverse(l);
        l = head;
        while(l != NULL && pal != NULL)
        {
            if (l->val != pal->val) return false;
            l = l->next;
            pal = pal->next;
        }
        return true;
    }
};

int main()
{
    Solution s;
    ListNode *h = new ListNode(1), *r;
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(2);
    h->next->next->next->next->next = new ListNode(1);
//     outputlist(h);
//     r = s.reverse(h);
//     outputlist(r);
    cout<<s.isPalindrome(h)<<endl;
}
