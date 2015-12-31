class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r(1, 0);
        if (n == 0) return r;
        r = grayCode(n - 1);
        int i, t = r.size();
        for (i = t - 1; i >= 0; --i)
            r.push_back(r[i]|(1<<(n - 1)));
        return r;
    }
};
