#include <iostream>
#include <vector>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> r;
        if (intervals.size() == 0)
        {
            r.push_back(newInterval);
            return r;
        }
        int i = 0, j;
        Interval ins;
        if (newInterval.start <= intervals[0].start)
        {
            ins.start = newInterval.start;
        }
        else
        {
            for(i = 0; i < intervals.size() - 1; ++i)
            {
                if (intervals[i].start <= newInterval.start && intervals[i + 1].start > newInterval.start) break;
                r.push_back(intervals[i]);
            }
            if (newInterval.start <= intervals[i].end) ins.start = intervals[i].start;
            else
            {
                r.push_back(intervals[i]);
                ins.start = newInterval.start;
            }
        }
        for(; i < intervals.size(); ++i)
            if (intervals[i].start > newInterval.end) break;
        ins.end = max(newInterval.end, intervals[i - 1].end);
        r.push_back(ins);
        for(; i < intervals.size(); ++i)
            r.push_back(intervals[i]);
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
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(6,9));
    r = s.insert(intervals, Interval(2,5));
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,9));
    r = s.insert(intervals, Interval(1,2));
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,9));
    r = s.insert(intervals, Interval(1,4));
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,9));
    r = s.insert(intervals, Interval(9,20));
    outputinterval(r);
    intervals.clear();
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,9));
    r = s.insert(intervals, Interval(10,20));
    outputinterval(r);
}
