class Solution {
public:
    static bool comp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> r;
        if (intervals.size() == 0) return r;
        sort(intervals.begin(), intervals.end(), comp);
        int i;
        for (i = 0; i < intervals.size();)
        {
            Interval cur = intervals[i++];
            while(i < intervals.size() && cur.end >= intervals[i].start)
                cur.end = max(cur.end, intervals[i++].end);
            r.push_back(cur);
        }
        return r;
    }
};
