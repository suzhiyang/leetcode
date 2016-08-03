class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersection(nums2, nums1);
        unordered_map<int, bool> h;
        int i;
        for (i = 0; i < nums1.size(); ++i)
            h[nums1[i]] = false;
        vector<int> r;
        for (i = 0; i < nums2.size(); ++i)
            if (h.find(nums2[i]) != h.end() && h[nums2[i]] == false)
            {
                h[nums2[i]] = true;
                r.push_back(nums2[i]);
            }
        return r;
    }
};
