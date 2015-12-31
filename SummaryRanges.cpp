class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i, j;
        vector<string> r;
        for (i = 0; i < nums.size();)
        {
            stringstream ss;
            ss<<nums[i];
            for (j = i; j + 1 < nums.size(); ++j)
                if (nums[j + 1] != nums[j] + 1) break;
            if (j == i) ++i;
            else
            {
                ss<<"->"<<nums[j];
                i = j + 1;
            }
            r.push_back(ss.str());
        }
        return r;
    }
};
