#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool depth(TreeNode *root, int n, int h)
    {
        TreeNode *t = root;
        int d = 0, i;
        for (i = h - 2; i >= 0; --i)
        {
            if ((n & (1<<i)) >> i == 0) t = t->left;
            else t = t->right;
            if (t == NULL) return false;
        }
        return true;
    }
    
    int countNodes(TreeNode* root) {
        int c = 0, h = 0;
        TreeNode *t = root;
        while(t != NULL)
        {
            t = t->left;
            ++h;
        }
        int l = 1<<(h - 1), r = (1 << h) - 1, mid, t1, t2;
        while(l <= r)
        {
            mid = (l + r) / 2;
            t1 = depth(root, mid, h);
            if (t1 == false) r = mid - 1;
            else
            {
                t2 = depth(root, mid + 1, h);
                if (t2 == false) break;
                l = mid + 1;
            }            
        }
        return mid;
    }
};

TreeNode *generate(int n)
{
    if (n == 0) return NULL;
    vector<TreeNode *> v;
    int i;
    for (i = 0; i < n; ++i)
    {
        TreeNode *t = new TreeNode(i);
        v.push_back(t);
    }
    for (i = 0; i < n / 2; ++i)
    {
        if (i * 2 + 1 < n) v[i]->left = v[i * 2 + 1];
        if (i * 2 + 2 < n) v[i]->right = v[i * 2 + 2];
    }
    return v[0];
}

void traverse(TreeNode *root)
{
    if (root == NULL) return;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
        cout<<t->val<<" "<<endl;
    }
}

int main()
{
//    TreeNode *t = generate(10);
//    traverse(t);
    Solution s;
    TreeNode *t = generate(10);
//    cout<<s.depth(t, 10, 4)<<endl;
//    cout<<s.depth(t, 5, 4)<<endl;
    for (int i = 0; i < 20; ++i)
    {
        TreeNode *t = generate(i);
        cout<<i<<":"<<s.countNodes(t)<<endl;
    }
}
