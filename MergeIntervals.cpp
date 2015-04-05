#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct comp {
    bool operator() (const Interval &a, const Interval &b) {return a.start < b.start;}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> r;
        sort(intervals.begin(), intervals.end(), comp());
        int i = 0;
        while(i < intervals.size())
        {
            Interval n(intervals[i].start, intervals[i].end);
            while(i < intervals.size() - 1 && intervals[i + 1].start <= n.end)
            {
                if (n.end < intervals[i + 1].end) n.end = intervals[i + 1].end;
                ++i;
            }
            r.push_back(n);
            ++i;
        }
        return r;
    }
};

void outputinterval(vector<Interval> &intervals)
{
    int i;
    for(i = 0; i < intervals.size(); ++i)
        cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"] ";
    cout<<endl;
}

int main()
{
    Solution s;
    vector<Interval> intervals, r;
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(15,18));
    r = s.merge(intervals);
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(2,3));
    r = s.merge(intervals);
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(4,5));
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(1,10));
    r = s.merge(intervals);
    outputinterval(r);
}
