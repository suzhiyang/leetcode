class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        map<int, vector<int> > g;
        vector<int> in(numCourses, 0);
        int i, j, v = numCourses;
        for (i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            ++in[prerequisites[i].first];
        }
        while(v--)
        {
            for (i = 0; i < numCourses; ++i)
                if (in[i] == 0) break;
            if (i == numCourses) return false;
            for (j = 0; j < g[i].size(); ++j)
                --in[g[i][j]];
            in[i] = -1;
        }
        return true;
    }
};
