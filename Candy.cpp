#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 1);
        int i;
        for (i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
        for (i = ratings.size() - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
                candy[i] = candy[i + 1] + 1;
        int t = 0;
        for (i = 0; i < candy.size(); ++i)
            t += candy[i];
        return t;
    }
};

int main()
{
    int r[] = {1,6,7,5,4};
    vector<int> ratings(r, r + 5);
    Solution s;
    cout<<s.candy(ratings)<<endl;
}
