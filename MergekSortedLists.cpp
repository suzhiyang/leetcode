#include <iostream>
#include <queue>
#include <vector>

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

class listnodecomp
{
public:
    bool operator()(const ListNode *lhs, const ListNode *rhs) const
    {
        return (lhs->val > rhs->val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, listnodecomp > pq;
        ListNode *head = new ListNode(0); // NULL pointer for simplicity
        ListNode *tail = head;
        int i;
        for(i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL) pq.push(lists[i]);
        while(!pq.empty())
        {
            ListNode *p = pq.top();
            pq.pop();
            if (p->next != NULL) pq.push(p->next);
            tail->next = p;
            tail = p;
        }
        ListNode *h = head->next;
        delete head;
        return h;
    }
};

int main()
{
    Solution s;
    vector<ListNode *> lists;
    s.mergeKLists(lists);
}
