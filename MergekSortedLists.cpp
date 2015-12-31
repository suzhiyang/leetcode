#include <vector>
#include <algorithm>
#include <queue>
#include "ds.h"

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *> > pq;
        ListNode dummy(0), *tail;
        tail = &dummy;
        vector<ListNode *> p(lists.size(), NULL);
        int i;
        for (i = 0; i < lists.size(); ++i)
        {
            p[i] = lists[i];
            if (p[i] != NULL)
                pq.push(make_pair(-p[i]->val, p[i]));
        }
        while(!pq.empty())
        {
            pair<int, ListNode *> t = pq.top();
            pq.pop();
            tail->next = t.second;
            tail = tail->next;
            if (t.second->next != NULL)
                pq.push(make_pair(-t.second->next->val, t.second->next));
        }
        return dummy.next;
    }
};

int main()
{
}
