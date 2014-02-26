#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* The subsets could be mapped to binary bits:
 * 000 001 010 ...
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        int c, tmp;
        vector<int> mask;
        mask.push_back(1);
        for (c = 1; c < S.size(); ++c)
        {
            tmp = mask[c - 1] * 2;
            mask.push_back(tmp);
        }
        for (c = 0; c < mask[mask.size() - 1] * 2; ++c)
        {
            vector<int> ss; //subset
            for (int i = 0; i < mask.size(); ++i)
            {
//                int flag = c & mask[mask.size() - 1 - i];
                if ((c & mask[mask.size() - 1 - i]) > 0) ss.push_back(S[i]);
            }
            result.push_back(ss);
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a[] = {3, 4, 1, 2};
    vector<int> t(a, a + 4);
    vector<vector<int> > r = s.subsets(t);
    for (int i = 0; i < r.size(); ++i)
    {
        cout<<"[";
        for(int j = 0; j < r[i].size(); ++j)
        {
            cout<<r[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
