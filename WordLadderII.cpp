#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<string> > &level, vector<vector<string> > &r, int index, vector<string> &cur)
    {
//         for (unordered_set<string>::iterator it = level[index].begin(); it != level[index].end(); ++it)
//             cout<<*it<<" ";
//         cout<<endl;
//         cout<<"------------"<<index<<endl;
        if (index == 0)
        {
            cur.push_back(*level[0].begin());
            r.push_back(cur);
            cur.pop_back();
            return;
        }
        int i, j;
        string str = *cur.rbegin();
        for (i = 0; i < str.size(); ++i)
        {
            char t = str[i];
            for (j = 0; j < 26; ++j)
            {
                str[i] = (char)(j + 'a');
                if (level[index].find(str) != level[index].end())
                {
                    cur.push_back(str);
                    dfs(level, r, index - 1, cur);
                    cur.pop_back();
                }
            }
            str[i] = t;
        }
    }
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > r;
        vector<unordered_set<string> > level;
        dict.erase(start); dict.insert(end);
        queue<string> q[2];
        int qc, qn, i, j;
        q[0].push(start);
        unordered_set<string> lset, found;
        for (qc = 0; !q[qc].empty(); qc ^= 1)
        {
            qn = qc ^ 1;
            lset.clear(); found.clear();
            bool isend = false;
            while(!q[qc].empty())
            {
                string str = q[qc].front();
                q[qc].pop();
                bool haschild = false;
                for (i = 0; i < str.size(); ++i)
                {
                    char t = str[i];
                    for (j = 0; j < 26; ++j)
                    {
                        str[i] = (char)(j + 'a');
                        if (dict.find(str) != dict.end())
                        {
                            q[qn].push(str);
                            found.insert(str);
                            if (str == end) isend = true;
                            haschild = true;
                        }
                    }
                    str[i] = t;
                }
                if (haschild == true) lset.insert(str);
            }
            if (!lset.empty()) level.push_back(lset);
            if (isend == true) break;
            for (unordered_set<string>::iterator it = found.begin(); it != found.end(); ++it)
                dict.erase(*it);
        }
//         for (i = 0; i < level.size(); ++i)
//         {
//             for (unordered_set<string>::iterator it = level[i].begin(); it != level[i].end(); ++it)
//                 cout<<*it<<" ";
//             cout<<"#"<<endl;
//         }
        vector<string> cur;
        cur.push_back(end);
        if (level.size() > 0)
            dfs(level, r, level.size() - 1, cur);
        for (i = 0; i < r.size(); ++i)
            reverse(r[i].begin(), r[i].end());
        return r;
    }
};

int main()
{
    Solution s;
    unordered_set<string> dict;
//    char d[][4] = {"hot", "got", "god", "dot", "dog", "lot", "log"};
//    char d[][4] = {"hot", "dog"};
    char d[][4] = {"hot","dot","dog"};
    for (int i = 0; i < sizeof(d) / sizeof(d[0]); ++i)
        dict.insert(d[i]);
//    vector<vector<string> > r = s.findLadders("hit", "cog", dict);
//    vector<vector<string> > r = s.findLadders("hot", "dog", dict);
    vector<vector<string> > r = s.findLadders("hot", "dot", dict);
    int i, j;
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
