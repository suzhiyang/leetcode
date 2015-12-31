#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> stk;
        int i, r = 0, area, tp;
        for (i = 0; i < height.size();)
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else
            {
                tp = stk.top();
                stk.pop();
                area = (stk.empty()?i:(i - stk.top() - 1)) * height[tp];
                r = max(r, area);
            }
        }
        while(!stk.empty())
        {
            tp = stk.top();
            stk.pop();
            area = ((stk.empty()?i:(i - stk.top() - 1))) * height[tp];
            r = max(r, area);
        }
        return r;
    }
};

int main()
{
    int a[] = {6, 2, 5, 4, 5, 1, 6}; //{2,1,5,6,2,3};
    vector<int> v(a, a + 7);
    Solution s;
    cout<<s.largestRectangleArea(v)<<endl;
}
