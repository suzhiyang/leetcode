#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> > &buildings) {
        vector<pair<int, int> > r;
        priority_queue<pair<int, int> > pq; // height:endtime
        int i = 0, curx = 0, curh = 0;
        while(i < buildings.size() || !pq.empty())
        {
            if (pq.empty() || (i < buildings.size() && pq.top().second >= buildings[i][0]))
            {
                curx = buildings[i][0];
                while(i < buildings.size() && buildings[i][0] == curx)
                {
                    pq.push(make_pair(buildings[i][2], buildings[i][1]));
                    ++i;
                }
            }
            else
            {
                curx = pq.top().second;
                while(!pq.empty() && pq.top().second <= curx)
                    pq.pop();
            }
            if (pq.empty()) curh = 0;
            else curh = pq.top().first;
            if (r.empty() || r.back().second != curh)
                r.push_back(make_pair(curx, curh));
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > b;
    int a[] = {0, 1, 3}, i;
    vector<int> v(a, a + 3);
    b.push_back(v);
    vector<pair<int, int> > sl = s.getSkyline(b);
    for (i = 0; i < sl.size(); ++i)
        cout<<"("<<sl[i].first<<","<<sl[i].second<<") ";
    cout<<endl;
}
