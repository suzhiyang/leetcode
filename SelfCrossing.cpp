class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int i;
        for (i = 3; i < x.size(); ++i)
        {
            if (x[i - 1] <= x[i - 3])
            {
                if (x[i] >= x[i - 2]) return true;
                else if (i > 3 && x[i] + x[i - 4] >= x[i - 2] && x[i - 2] > x[i - 4]
                && x[i - 1] + x[i - 5] >= x[i - 3]) return true;
            }
        }
        return false;
    }
};
