#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<unordered_set<string> > ladder(1, unordered_set<string>());
        vector<vector<string> > r;
        queue<string> q;
        unordered_set<string> visited;
        int level = 1, i, j, k;
        q.push(beginWord);
        ladder[0].insert(beginWord);
        visited.insert(beginWord);
        bool found = false;
        while(!q.empty() && found == false)
        {
            ladder.push_back(unordered_set<string>());
            int ql = q.size();
            for (i = 0; i < ql; ++i)
            {
                string t = q.front();
                q.pop();
                for (j = 0; j < t.size(); ++j)
                {
                    int tmp = t[j];
                    for (k = 'a'; k <= 'z'; ++k)
                    {
                        t[j] = k;
                        if (t == endWord) found = true;
                        if (visited.find(t) == visited.end() &&
                            wordList.find(t) != wordList.end())
                        {
                            visited.insert(t);
                            q.push(t);
                            ladder[level].insert(t);
                        }
                    }
                    t[j] = tmp;
                }
            }
            ++level;
        }
        if (found)
        {
            ladder.pop_back();
            reverse(ladder.begin(), ladder.end());
            // for (int i = 0; i < ladder.size(); ++i)
            // {
            //     for (auto j : ladder[i])
            //         cout<<j<<",";
            //     cout<<endl;
            // }
            vector<string> cur(1, endWord);
            dfs(r, cur, ladder);
        }
        return r;
    }

    void dfs(vector<vector<string> > &r, vector<string> &cur, vector<unordered_set<string> > &ladder)
    {
        if (cur.size() == ladder.size())
        {
            cur.push_back(*ladder.back().begin());
            r.push_back(cur);
            reverse(r.back().begin(), r.back().end());
            cur.pop_back();
        }
        else
        {
            int i, j, level = cur.size() - 1;
            string t = cur.back();
            for (i = 0; i < t.size(); ++i)
            {
                int tmp = t[i];
                for (j = 'a'; j <= 'z'; ++j)
                {
                    t[i] = j;
                    if (ladder[level].find(t) != ladder[level].end())
                    {
                        cur.push_back(t);
                        dfs(r, cur, ladder);
                        cur.pop_back();
                    }
                }
                t[i] = tmp;
            }
        }
    }
};

int main()
{
    Solution s;
    unordered_set<string> wordlist;
    wordlist.insert("hot");
    wordlist.insert("dot");
    wordlist.insert("dog");
    wordlist.insert("lot");
    wordlist.insert("log");
    // wordlist.insert("hkt");
    // wordlist.insert("hkg");
    // wordlist.insert("hog");
    vector<vector<string> > r;
    r = s.findLadders("hit", "cog", wordlist);
    for (int i = 0; i < r.size(); ++i)
    {
        for (int j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
    cout<<endl;
}
