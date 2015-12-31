class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> r;
        int i;
        for (i = 0; i < intervals.size(); ++i)
            if (intervals[i].end >= newInterval.start) break;
            else r.push_back(intervals[i]);
        if (i >= intervals.size())
        {
            r.push_back(newInterval);
            return r;
        }
        Interval cur;
        cur.start = min(intervals[i].start, newInterval.start);
        cur.end = max(cur.end, newInterval.end);
        while(i < intervals.size() && cur.end >= intervals[i].start)
            cur.end = max(cur.end, intervals[i++].end);
        r.push_back(cur);
        while(i < intervals.size())
            r.push_back(intervals[i++]);
        return r;
    }
};
