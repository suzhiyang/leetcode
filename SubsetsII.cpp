#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/* The subsets could be mapped to binary bits:
 * 000 001 010 ...
 */
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        set<vector<int> > r;
        sort(S.begin(), S.end());
        int c, tmp;
        vector<int> mask;
        mask.push_back(1);
        for (c = 1; c < S.size(); ++c)
        {
            tmp = mask[c - 1] << 1;
            mask.push_back(tmp);
        }
        for (c = 0; c < mask[mask.size() - 1] << 1; ++c)
        {
            vector<int> ss; //subset
            for (int i = 0; i < mask.size(); ++i)
            {
                if ((c & mask[mask.size() - 1 - i]) > 0) ss.push_back(S[i]);
            }
            r.insert(ss);
        }
        vector<vector<int> > result;
        copy(r.begin(), r.end(), back_inserter(result));
        return result;
    }
};

int main()
{
    Solution s;
    int a[] = {2, 1, 2};
    vector<int> t(a, a + sizeof(a) / 4);
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
