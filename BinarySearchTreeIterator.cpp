#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> m_s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *t = root;
        while (t != NULL)
        {
            m_s.push(t);
            t = t->left;
        }
    }

    bool hasNext() {
        if (m_s.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *t = m_s.top(), *n;
        m_s.pop();
        if (t->right != NULL)
        {
            n = t->right;
            while(n != NULL)
            {
                m_s.push(n);
                n = n->left;
            }
        }
        return t->val;
    }
};

int main()
{
    //                       5
    //                     /   \
    //                    3     8
    //                   / \     \
    //                  2   4     9
    //                 /           \
    //                1            10
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() <<",";
    cout<<endl;
    return 0;
}
