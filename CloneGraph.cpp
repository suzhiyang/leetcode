class Solution {
private:
    map<int, UndirectedGraphNode *> v;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (v.find(node->label) == v.end())
        {
            v[node->label] = new UndirectedGraphNode(node->label);
            for (int i = 0; i < node->neighbors.size(); ++i)
            {
                UndirectedGraphNode *newnode = cloneGraph(node->neighbors[i]);
                v[node->label]->neighbors.push_back(newnode);
            }
        }
        return v[node->label];
    }
};
