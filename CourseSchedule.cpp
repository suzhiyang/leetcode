#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
        int i;
        vector<int> in(numCourses, 0);
        vector<vector<int> > g(numCourses, vector<int>());
        stack<int> s;
        for (i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++in[prerequisites[i][0]];
        }
        for (i = 0; i < numCourses; ++i)
            if (in[i] == 0) s.push(i);
        int n = numCourses;
        while(!s.empty())
        {
            int t = s.top();
            s.pop();
            --n;
            for (i = 0; i < g[t].size(); ++i)
            {
                if (--in[g[t][i]] == 0)
                    s.push(g[t][i]);
            }
        }
        if (n > 0) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > p;
    vector<int> v;
    cout<<s.canFinish(1, p)<<endl;
    v.push_back(1); v.push_back(0);
    p.push_back(v);
    cout<<s.canFinish(2, p)<<endl;
}
