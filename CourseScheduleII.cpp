#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        int i;
        vector<int> r, in(numCourses, 0);
        vector<vector<int> > v(numCourses, vector<int>());
        stack<int> s;
        for (i = 0; i < prerequisites.size(); ++i)
        {
            ++in[prerequisites[i].first];
            v[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for (i = 0; i < numCourses; ++i)
            if (in[i] == 0) s.push(i);
        while(!s.empty())
        {
            int t = s.top();
            s.pop();
            r.push_back(t);
            for (i = 0; i < v[t].size(); ++i)
                if (--in[v[t][i]] == 0) s.push(v[t][i]);
        }
        if (r.size() < numCourses) r.clear();
        return r;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > v;
    vector<int> r = s.findOrder(2, v);
    cout<<r.size()<<endl;
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
    
}
