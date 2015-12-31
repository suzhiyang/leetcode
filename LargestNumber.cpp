bool comp(const string &a, const string &b)
{
    return (a + b) > (b + a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            stringstream ss;
            ss<<nums[i];
            v.push_back(ss.str());
        }
        sort(v.begin(), v.end(), comp);
        string r;
        bool leading0 = true;
        for (int i = 0; i < v.size(); ++i)
        {
            if (leading0 && v[i] == "0" && i != v.size() - 1) continue;
            leading0 = false;
            r += v[i];
        }
        return r;
    }
};
