#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (prices.size() < 2) return 0;
        int i, j, min = INT_MAX, profit = 0, t;
        vector<int> p1(n, 0), p2(n, 0);
        for(i = 0; i < n; ++i)
        {
            if (prices[i] < min) min = prices[i];
            t = prices[i] - min;
            if (t > profit) profit = t;
            p1[i] = profit;
        }
        int max = INT_MIN;
        profit = 0;
        for(i = n - 1; i >= 0; --i)
        {
            if (prices[i] > max) max = prices[i];
            t = max - prices[i];
            if (t > profit) profit = t;
            p2[i] = profit;
        }
        profit = 0;
        for(i = 0; i < n; ++i)
            if (p1[i] + p2[i] > profit) profit = p1[i] + p2[i];
        return profit;
    }
};

int main()
{
    Solution s;
    int a[] = {2,1,3,8,6};
//    int a[] = {2,1,8,5,6,9};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    cout<<s.maxProfit(v)<<endl;
}
