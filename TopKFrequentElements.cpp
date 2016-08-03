class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i;
        for (i = 0; i < nums.size(); ++i)
            ++freq[nums[i]];
        priority_queue<pair<int, int> > pq;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            pq.push(make_pair(it->second, it->first));
        vector<int> r;
        for (i = 0; i < k; ++i)
        {
            r.push_back(pq.top().second);
            pq.pop();
        }
        return r;
    }
};
