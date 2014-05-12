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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p = head;
        int len = 0;
        while(p != NULL)
        {
            ++len;
            p = p->next;
        }
        return convert(head, len);
    }

    TreeNode *convert(ListNode *head, int num)
    {
        if (num == 0) return NULL;
        TreeNode *root = new TreeNode(0);
        int mid = num / 2;
        ListNode *p = head;
        for(int i = 0; i < mid; ++i)
            p = p->next;
        root->val = p->val;
        root->left = convert(head, mid);
        root->right = convert(p->next, num - mid - 1);
        return root;
    }
};

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > r;
    if (root == NULL) return r;
    queue<pair<TreeNode *, int> > q;
    q.push(make_pair(root, 0));
    vector<int> leveli; //level i
    int currentlevel = 0;
    while(!q.empty())
    {
        pair<TreeNode *, int> t = q.front();
        q.pop();
        if (t.second > currentlevel)
        {
            r.push_back(leveli);
            leveli.clear();
            currentlevel = t.second;
        }
        leveli.push_back(t.first->val);
        if (t.first->left != NULL) q.push(make_pair(t.first->left, t.second + 1));
        if (t.first->right != NULL) q.push(make_pair(t.first->right, t.second + 1));
    }
    if (!leveli.empty()) r.push_back(leveli);
    return r;
}

int main()
{
    Solution s;
    ListNode *l[10];
    l[0] = new ListNode(1);
    l[1] = new ListNode(2);
    l[2] = new ListNode(3);
    l[3] = new ListNode(4);
    l[4] = new ListNode(5);
    l[5] = new ListNode(6);
    l[0]->next = l[1];
    l[1]->next = l[2];
    l[2]->next = l[3];
    l[3]->next = l[4];
    l[4]->next = l[5];
    TreeNode *root = s.sortedListToBST(l[0]);

    vector<vector<int> > r = levelOrder(root);
    for (int i = 0; i < r.size(); ++i)
    {
        for(int j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }

}
