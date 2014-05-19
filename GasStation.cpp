#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, startpoint = 0, diff = INT_MIN, mincost = INT_MAX, g = 0, c = 0;
        for(i = 0; i < gas.size(); ++i)
        {
            g += gas[i];
            c += cost[i];
            if (gas[i] - cost[i] > diff || (gas[i] - cost[i] == diff && cost[i] < mincost))
            {
                startpoint = i;
                diff = gas[i] - cost[i];
                mincost = cost[i];
            }
        }
        if (g < c) return -1;
        int t = startpoint, curgas = 0;
        for(i = 0; i < gas.size(); ++i)
        {
            curgas = curgas + gas[t] - cost[t];
//            cout<<t<<"*"<<curgas<<endl;
            if (curgas < 0) return -1;
            t = (t + 1) % gas.size();
        }
        return startpoint;
    }
};

int main()
{
//    int a[] = {1,2,3,4,5}, b[] = {3,4,5,1,2};
    int a[] = {1,2,3,3}, b[] = {2,1,5,1};
//    int a[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
//    int b[] = {27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    vector<int> gas(a, a + sizeof(a) / 4);
    vector<int> cost(b, b + sizeof(b) / 4);
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost)<<endl;
}
