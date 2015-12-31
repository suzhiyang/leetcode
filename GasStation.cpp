class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = 0, c = 0, mci = 0, i; // most cost index
        for (i = 0; i < gas.size(); ++i)
        {
            g += gas[i]; c += cost[i];
            if (gas[i] - cost[i] < gas[mci] - cost[mci])
                mci = i;
        }
        if (g < c) return -1;
        while(gas[mci] - cost[mci] < 0) mci = (mci + 1) % gas.size();
        return mci;
    }
};
