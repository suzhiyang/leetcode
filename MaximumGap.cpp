#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        int maxnum = num[0], minnum = num[0], i;
        for (i = 0; i < num.size(); ++i)
        {
            maxnum = max(maxnum, num[i]);
            minnum = min(minnum, num[i]);
        }
        int len = (maxnum - minnum) / num.size() + 1, index;
        vector<vector<int> > bucket((maxnum - minnum) / len + 1);
        for (i = 0; i < num.size(); ++i)
        {
            index = (num[i] - minnum) / len;
            if (bucket[index].empty())
            {
                bucket[index].push_back(num[i]);
                bucket[index].push_back(num[i]);
            }
            else
            {
                bucket[index][0] = min(bucket[index][0], num[i]);
                bucket[index][1] = max(bucket[index][1], num[i]);
            }
        }
        int gap = 0, prev = 0;
        for (i = 1; i < bucket.size(); ++i)
        {
            if (bucket[i].empty()) continue;
            gap = max(gap, bucket[i][0] - bucket[prev][1]);
            prev = i;
        }
        return gap;
    }
};
