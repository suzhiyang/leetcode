#include <string>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int r = 1, i, j;
        queue<string> q;
        unordered_set<string> searched;
        q.push(beginWord);
        q.push("");
        while(!q.empty())
        {
            string t = q.front();
            q.pop();
            if (t == "")
            {
                if (q.empty()) break;
                q.push("");
                ++r;
            }
            else
            {
                for (i = 0; i < t.size(); ++i)
                {
                    int tmp = t[i];
                    for (j = 'a'; j <= 'z'; ++j)
                    {
                        t[i] = j;
                        if (t == endWord) return r + 1;
                        if (searched.find(t) == searched.end() &&
                            wordList.find(t) != wordList.end())
                        {
                            searched.insert(t);
                            q.push(t);
                        }
                    }
                    t[i] = tmp;
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    unordered_set<string> wordlist;
    wordlist.insert("hot");
    wordlist.insert("dog");
    wordlist.insert("dot");
    cout<<s.ladderLength("hot", "dog", wordlist)<<endl;
}
