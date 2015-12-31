#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > g(n, vector<int>());
        vector<int> deg(n, 0);
        int i, j;
        for (i = 0; i < edges.size(); ++i)
        {
            g[edges[i].first].push_back(edges[i].second);
            g[edges[i].second].push_back(edges[i].first);
            ++deg[edges[i].first], ++deg[edges[i].second];
        }
        vector<int> leaves[2];
        int cur = 0, next = 1;
        for (i = 0; i < n; ++i)
            if (deg[i] <= 1) leaves[cur].push_back(i);
        while(n > 2)
        {
            n -= leaves[cur].size();
            for (i = 0; i < leaves[cur].size(); ++i)
            {
                int l = leaves[cur][i];
                for (j = 0; j < g[l].size(); ++j)
                {
                    --deg[g[l][j]], --deg[l];
                    if (deg[g[l][j]] == 1) leaves[next].push_back(g[l][j]);
                }
            }
            leaves[cur].clear();
            swap(cur, next);
        }
        return leaves[cur];
    }
};

int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(1, 3));
    vector<int> r = Solution().findMinHeightTrees(4, v);
    for (auto a : r)
        cout<<a<<endl;
}
