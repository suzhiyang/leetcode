class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if (citations[mid] == n - mid) break;
            else if (citations[mid] < n - mid) l = mid + 1;
            else r = mid - 1;
        }
        if (l <= r) return n - mid;
        else return n - right - 1;
    }
};
