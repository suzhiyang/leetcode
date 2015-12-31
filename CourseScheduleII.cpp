class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> r;
        map<int, vector<int> > g;
        vector<int> in(numCourses, 0);
        int i, j, k;
        for (i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            ++in[prerequisites[i].first];
        }
        for (j = 0; j < numCourses; ++j)
        {
            for (i = 0; i < numCourses; ++i)
                if (in[i] == 0) break;
            if (i == numCourses) return vector<int>();
            r.push_back(i);
            in[i] = -1;
            for (k = 0; k < g[i].size(); ++k)
                --in[g[i][k]];
        }
        return r;
    }
};
