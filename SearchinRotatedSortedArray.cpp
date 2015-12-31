class Solution {
public:
    int search(vector<int>& a, int target) {
        int l = 0, r = a.size() - 1, m;
        while(l <= r)
        {
            m = (l + r) / 2;
            if (target == a[m]) return m;
            if (a[m] < a[r])
            {
                if (target > a[m] && target <= a[r])
                    l = m + 1;
                else r = m - 1;
            }
            else
            {
                if (target >= a[l] && target < a[m])
                    r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};
