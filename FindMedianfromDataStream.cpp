class MedianFinder {
public:
    priority_queue<int> lq, rq;

    // Adds a number into the data structure.
    void addNum(int num) {
        if (lq.empty() || num <= lq.top()) lq.push(num);
        else rq.push(-num);
        if (lq.size() > rq.size() + 1)
        {
            rq.push(-lq.top());
            lq.pop();
        }
        else if (lq.size() < rq.size())
        {
            lq.push(-rq.top());
            rq.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if ((lq.size() + rq.size()) % 2 == 0) return (lq.top() - rq.top()) / 2.0;
        return lq.top();
    }
};
