#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode *m_prev;
public:
    Solution() : m_prev(NULL) {}
    
    void HierarchyTravel(TreeLinkNode *root, int level)
    {
        if (root == NULL) return;
        if (level == 0)
        {
            if (m_prev != NULL) m_prev->next = root;
            m_prev = root;
        }
        if (root->left != NULL) HierarchyTravel(root->left, level - 1);
        if (root->right != NULL) HierarchyTravel(root->right, level - 1);
    }
    
    void connect(TreeLinkNode *root) {
        int level = 0;
        while(1)
        {
            m_prev = NULL;
            HierarchyTravel(root, level++);
            if (m_prev != NULL) m_prev->next = NULL;
            else break;
        }
    }
};

int main()
{
//                  1
//                /  \
//               2    3
//              / \    \
//             4   5    7
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right = new TreeLinkNode(3);
    root->right->right = new TreeLinkNode(7);

    Solution s;
//    s.HierarchyTravel(root, 2);
//    cout<<endl;
    root = new TreeLinkNode(1);
    s.connect(root);
}
