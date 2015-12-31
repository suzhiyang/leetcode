#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        priority_queue<pair<int, int> > pq; //height: r
        int i = 0, curh = 0, curx = 0;
        vector<pair<int, int> > res;
        while(i < buildings.size() || !pq.empty())
        {
            if (pq.empty() || (i < buildings.size() && pq.top().second >= buildings[i][0]))
            {
                curx = buildings[i][0];
                while(i < buildings.size() && curx == buildings[i][0])
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
            curh = pq.empty()? 0 : pq.top().first;
            if (res.empty() || res.back().second != curh)
                res.push_back(make_pair(curx, curh));
        }
        return res;
    }
};

int main()
{
}
