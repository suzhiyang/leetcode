/* I think the graph serialization has some problems:
 * for the given undirected graph,
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 * the neighbors for 1 should be: <0,2> instead of <2>.
 *
 * Using the serialization given by the problem, the graph can only be
 * traversed from node 0, not an arbitrary node.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        queue<UndirectedGraphNode *> q; // store nodes that not process neighbors
        map<int, UndirectedGraphNode *> visited; // store <label: new nodes> mapping
        q.push(node);
        while(q.size() > 0)
        {
            UndirectedGraphNode *t = q.front();
            q.pop();
            map<int, UndirectedGraphNode *>::iterator it;
            UndirectedGraphNode *clonenode;
            it = visited.find(t->label);
            if (it == visited.end())
            {
                clonenode = new UndirectedGraphNode(t->label);
                visited[t->label] = clonenode;
            }
            else clonenode = it->second;
            for(int i = 0; i < t->neighbors.size(); ++i)
            {
                int l = t->neighbors[i]->label;
                it = visited.find(l);
                if (it == visited.end())
                {
                    UndirectedGraphNode *n = new UndirectedGraphNode(l);
                    visited[l] = n;
                    clonenode->neighbors.push_back(n);
                    q.push(t->neighbors[i]);
                }
                else
                {
                    clonenode->neighbors.push_back(it->second);
                }
            }
        }
        return visited[node->label];
    }
};

void printgraph(UndirectedGraphNode *node)
{
    queue<UndirectedGraphNode *> q;
    map<int, UndirectedGraphNode *> visited;
    q.push(node);
    while(q.size() > 0)
    {
        UndirectedGraphNode *t = q.front();
        q.pop();
        map<int, UndirectedGraphNode *>::iterator it;
        it = visited.find(t->label);
        if (it == visited.end())
        {
            visited[t->label] = t;
            cout<<t->label<<":";
            for(int i = 0; i < t->neighbors.size(); ++i)
            {
                int l = t->neighbors[i]->label;
                it = visited.find(l);
                if (it == visited.end())
                {
                    q.push(t->neighbors[i]);
                }
                cout<<l<<",";
            }
        }
        cout<<endl;
    }
}

int main()
{
    UndirectedGraphNode *g[3];
    g[0] = new UndirectedGraphNode(0);
    g[1] = new UndirectedGraphNode(1);
    g[2] = new UndirectedGraphNode(2);
    g[0]->neighbors.push_back(g[1]);
    g[0]->neighbors.push_back(g[2]);
    g[1]->neighbors.push_back(g[2]);
    g[2]->neighbors.push_back(g[2]);
    Solution s;
    printgraph(g[0]);
    UndirectedGraphNode *n;
    n = s.cloneGraph(g[0]);
    printgraph(n);
}
